# Laravel Vue.js CRUD 예시 - 사진업로드와 페이지네이션

2020 12 10

Laravel을 공부하면서, Vue 로 프론트엔드를 만드는 작업을 하고 있었다. Django에는 template에서 바로 변수를 부를 수 있고, 아니면 다른 프레임워크들 내부에도 템플릿을 띄워주는 게있다. Laravel에도 마찬가지로 blade로 프론트 작업을 할 수 있었다. 하지만 Vue를 사용해 보고 싶었기에 Vue를 사용하게 되었다. 이 글은 php, composer, node, npm이 다 설치가 되어있는 상태에서 시작을 하기 바란다.

https://www.codecheef.org/article/laravel-vue-js-crud-example-with-file-upload-and-pagination

이 글을 한글로 요약 한 글이다.

---

#### 1. Laravel 시작

```bash
$ composer create-project --prefer-dist laravel/laravel blog
```

#### 2. Upload 모델 생성
```bash
$ php artisan make:model Upload -m
```

생성 후 database/migrations 폴더로 가서 가장 최근에 생긴 파일로 들어가면 **CreateUploadsTable** 클래스 파일이 보인다. 여기서

```php
Schema::create('uploads', function (Blueprint $table) {
    $table->bigIncrements('id');
    $table->string('name');
    $table->string('photo');
    $table->timestamps();
});
```

로 고쳐준다.



#### 3. API routes 설정

**routes/api.php**로 간 뒤 다음 코드를 붙여넣어준다.

```php
Route::apiResources(
	[
		'photo' => 'API\PhotoController'
	]
);
```

그리고 Controller를 만들어 준다. 그러면 `app/Http/Controllers/API/PhotoController.php.`에 파일이 생긴다.

```bash
$ php artisan make:controller API/PhotoController --api
```

#### 4. vue 설치

프로젝트 디렉토리 가장 바깥에서 명령어를 실행한다.

```bash
$ npm i
$ npm i vue
$ npm i vue-router
$ npm i axios vform
$ npm i laravel-vue-pagination
$ npm install sweetalert2
$ composer require intervention/image /* image intervention 설치 */
```

위의 설치를 끝마치고, 

`config/app.php` 파일을 연다

```php
'providers' => [
		...
        Intervention\Image\ImageServiceProvider::class,
    ],
'aliases' => [
        ...
        'Image' => Intervention\Image\Facades\Image::class,

    ],
```

를 추가해준다.



#### 5. app.js 파일 설정

`resources/js/app.js` 파일에 들어가서

```javascript
require('./bootstrap');

window.Vue = require('vue');

//Import View Router
import VueRouter from 'vue-router'
Vue.use(VueRouter)

//Pagination laravel-vue-pagination
Vue.component('pagination', require('laravel-vue-pagination'));

//Import Sweetalert2
import Swal from 'sweetalert2'
window.Swal = Swal
const Toast = Swal.mixin({
  toast: true,
  position: 'top-end',
  showConfirmButton: false,
  timer: 3000,
  timerProgressBar: true,
  onOpen: (toast) => {
    toast.addEventListener('mouseenter', Swal.stopTimer)
    toast.addEventListener('mouseleave', Swal.resumeTimer)
  }
})
window.Toast = Toast

//Import v-from
import { Form, HasError, AlertError } from 'vform'
window.Form = Form;
Vue.component(HasError.name, HasError)
Vue.component(AlertError.name, AlertError)


//Routes
import { routes } from './routes';

//Register Routes
const router = new VueRouter({
    routes, 
    mode: 'hash',

})

const app = new Vue({
    el: '#app',
    router,  
});
```

로 변경시켜준다.

`resources/js/routes.js` 파일을 생성해주고

```javascript
import Upload from './components/admin/UploadComponent.vue'

export const routes = [
   
    { 
        path:'/upload',
        component:Upload
    },
 
];
```

내용을 붙여넣어준다.

#### 6. 컨트롤러 설정

`app/Http/Controllers/API/PhotoController.php` 파일을 실행시켜 다음 내용을 붙인다.

```php
namespace App\Http\Controllers\API;

use App\Http\Controllers\Controller;
use App\Upload;
use Illuminate\Http\Request;

class PhotoController extends Controller
{

    public function index()
    {
        return Upload::latest()->paginate(1);
    }

    public function store(Request $request)
    {
        $this->validate($request,[
            'name' => 'required|string|max:191',
            'photo' => 'required'
        ]);

        if($request->photo){

            $name = time().'.' . explode('/', explode(':', substr($request->photo, 0, strpos($request->photo, ';')))[1])[1];
            \Image::make($request->photo)->save(public_path('img/profile/').$name);
            $request->merge(['photo' => $name]);
           
        }

        Upload::create($request->all());

        return ['message' => 'Success'];

    }

    public function show($id)
    {
        //
    }

    public function update(Request $request, $id)
    {
        $upload = Upload::find($id);

        $this->validate($request,[
            'name' => 'required|string|max:191',
            'photo' => 'required'
        ]);

        $currentPhoto = $upload->photo;

        if($request->photo != $currentPhoto){

            $name = time().'.' . explode('/', explode(':', substr($request->photo, 0, strpos($request->photo, ';')))[1])[1];
            \Image::make($request->photo)->save(public_path('img/profile/').$name);
            $request->merge(['photo' => $name]);

            $userPhoto = public_path('img/profile/').$currentPhoto;

            if(file_exists($userPhoto)){

                @unlink($userPhoto);
                
            }
           
        }

        $upload->update($request->all());

        return ['message' => 'Success'];
    }

    public function destroy($id)
    {
        $upload = Upload::findOrFail($id);

        $upload->delete();

        $currentPhoto = $upload->photo;

        $userPhoto = public_path('img/profile/').$currentPhoto;

        if(file_exists($userPhoto)) {

            @unlink($userPhoto);
                
        }

        return [
         'message' => 'Photo deleted successfully'
        ];
    }
}
```



#### 7. 블레이드 파일 생성

`resources/views/master.blade.php` 파일을 생성해주고 다음 내용 복사

```php

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <meta http-equiv="x-ua-compatible" content="ie=edge">

  <title>Vue js App</title>
  <meta name="csrf-token" content="{{ csrf_token() }}">
  <link rel="stylesheet" href="{{ mix('css/app.css') }}">
</head>

<body class="hold-transition sidebar-mini">
<div class="wrapper" id="app">

  <aside class="main-sidebar sidebar-dark-primary elevation-4">
    <div class="sidebar">
      <nav class="mt-2">
        <ul class="nav nav-pills nav-sidebar flex-column" data-widget="treeview" role="menu" data-accordion="false">
          
          <li class="nav-item">
                <router-link to="/upload" class="nav-link">
                    <i class="nav-icon fas fa-user orange"></i>
                    <p>
                        Upload File
                    </p>
                </router-link>
         </li>

        </ul>
      </nav>
    </div>
  </aside>

  <div class="content-wrapper">
    <div class="content">
      <div class="container-fluid">

        <router-view></router-view>
    
      </div>
    </div>
  </div>
</div>


<script src="{{ mix('js/app.js') }}"></script>
</body>
</html> 
```

그다음 `resources/js`에 `components/admin` 디렉터리를 만들어 준다. 그리고 **UploadComponenet.vue** 파일을 생성해준다. 최종 경로는 `resources / js / components / admin / UploadComponent.vue` 가 된다

```vue

<template>
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-md-8">
                <div class="card">
                    <div class="card-header">Upload Profile</div>

                    <div class="card-body">

           <div class="card card-primary card-outline">
              <div class="card-body box-profile">
                <div class="text-center">
                  <img class="profile-user-img img-fluid img-circle" :src="getPhoto()" alt="User profile picture">
                </div>
              </div>
            </div>


  <div class="tab-pane active" id="settings">
      <form class="form-horizontal">
        <div class="form-group row">
          <label for="inputName" class="col-sm-2 col-form-label">Name</label>
          <div class="col-sm-10">
            <input type="email" v-model="form.name" class="form-control" :class="{ 'is-invalid': form.errors.has('name') }">
          <has-error :form="form" field="name"></has-error> 
          </div>
        </div>

        <div class="form-group row">
          <label for="inputSkills" class="col-sm-2 col-form-label">Avatar</label>
          <div class="col-sm-10">
            <input type="file" @change='uploadPhoto' name="photo" class="form-control" :class="{ 'is-invalid': form.errors.has('photo') }">
            <has-error :form="form" field="photo"></has-error> 
          </div>
        </div>
       
        <div class="form-group row">
          <div class="offset-sm-2 col-sm-10">
            <button type="submit" @click.prevent="SubmitPhoto" class="btn btn-danger">Submit</button>
          </div>
        </div>
      </form>
      </div>

  <div class="card-body table-responsive p-0">
    <table class="table table-hover">
      <tbody>
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Photo</th>
            <th>Modify</th>
      </tr> 

      <tr v-for="item in tabledata.data" :key="item.id">
        <td>{{ item.id }}</td>
        <td>{{ item.name }}</td>
        <td><img :src="`img/profile/${item.photo}`" class="profile-user-img img-fluid img-circle" style="height:40px; width:40px;"></td>
  
        <td>
            <a href="#" @click="editPhotoModal(item)">
                <i class="fa fa-edit blue"></i>
            </a>
            |
            <a href="#" @click="deletePhoto(item.id)">
                <i class="fa fa-trash red"></i>
            </a>

        </td>
      </tr>
    </tbody></table>
    <pagination :data="tabledata" @pagination-change-page="getResults"></pagination>
  </div>

    <div class="modal fade" id="addNew" tabindex="-1" role="dialog" aria-labelledby="addNewLabel" aria-hidden="true">
            <div class="modal-dialog modal-dialog-centered" role="document">
                <div class="modal-content">
                <div class="modal-header">

                    <h5 class="modal-title" id="addNewLabel">Update Photo</h5>

                    <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                    <span aria-hidden="true">&times;</span>
                    </button>
                </div>

<form @submit.prevent="UpdatePhoto">
<div class="modal-body">

     <div class="form-group">
        <input v-model="form.name" type="text" name="name"
            placeholder="Name"
            class="form-control" :class="{ 'is-invalid': form.errors.has('name') }">
        <has-error :form="form" field="name"></has-error>
    </div>

      <div class="form-group row">
        <label for="inputSkills" class="col-sm-2 col-form-label">Avatar</label>
          <div class="col-sm-10">
            <input type="file" @change='uploadPhoto' name="photo" class="form-control" :class="{ 'is-invalid': form.errors.has('photo') }">
            <has-error :form="form" field="photo"></has-error> 
        </div>
      </div>
      <img class="profile-user-img img-fluid img-circle" :src="getPhoto()" alt="User profile picture">
    
</div>
<div class="modal-footer">
    <button type="button" class="btn btn-danger" data-dismiss="modal">Close</button>
    <button type="submit" class="btn btn-primary">Update</button>
</div>

       </form>
     </div>
   </div>
</div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</template>

<script>
    export default {

        data(){
            return {
                tabledata: {},
                form: new Form({
                    id: '',
                    name : '',
                    photo: ''
                })
            }
        },
        methods: {

            uploadPhoto(e){
              let file = e.target.files[0];
                let reader = new FileReader();  

                if(file['size'] < 2111775)
                {
                    reader.onloadend = (file) => {
                    //console.log('RESULT', reader.result)
                     this.form.photo = reader.result;
                    }              
                     reader.readAsDataURL(file);
                }else{
                    alert('File size can not be bigger than 2 MB')
                }
            },

            //For getting Instant Uploaded Photo
            getPhoto(){
               let photo = (this.form.photo.length > 100) ? this.form.photo : "img/profile/"+ this.form.photo;
                return photo;
            },

            //Insert Photo
            SubmitPhoto(){

            this.form.post('api/photo')
               .then(()=>{

                   Toast.fire({
                      icon: 'success',
                      title: 'File uploaded successfully'
                    })
                   this.loadTableData()
               })
               .catch(()=>{
                  console.log("Error.....")
               })

            },

            //get Table data
            loadTableData(){

                axios.get('api/photo')
                   .then(({ data }) =>( this.tabledata = data))
                   .catch(()=>{
                      console.log("Error...")
                   })
            },

            //Pagination
            getResults(page = 1) {
                  axios.get('api/photo?page=' + page)
                    .then(response => {
                      this.tabledata = response.data;
                  });
            },

            //Edit Option
            editPhotoModal(item){
               this.form.clear();
               this.form.reset();
               $('#addNew').modal('show');
               this.form.fill(item)
            },

            UpdatePhoto(){
              this.form.put('api/photo/'+this.form.id)
               .then(()=>{

                   Toast.fire({
                      icon: 'success',
                      title: 'Photo updated successfully'
                    })

                    this.loadTableData()

                    $('#addNew').modal('hide');
               })
               .catch(()=>{
                  console.log("Error.....")
               })
            },

            //Delete photo
            deletePhoto(id){
                Swal.fire({
                title: 'Are you sure?',
                text: "You won't be able to revert this!",
                icon: 'warning',
                showCancelButton: true,
                confirmButtonColor: '#3085d6',
                cancelButtonColor: '#d33',
                confirmButtonText: 'Yes, delete it!'
              }).then((result) => {
                      
              if (result.value) {
                //Send Request to server
                this.form.delete('api/photo/'+id)
                    .then((response)=> {
                            Swal.fire(
                              'Deleted!',
                              'Photo deleted successfully',
                              'success'
                            )
                    this.loadTableData();

                    }).catch(() => {
                        Swal.fire({
                          icon: 'error',
                          title: 'Oops...',
                          text: 'Something went wrong!',
                          footer: '<a href>Why do I have this issue?</a>'
                        })
                    })
                }

            })
            }
                  
        },

        created() {
          
          //LoadTableData
          this.loadTableData()
            
        }
        
    }
</script>
```



마이그레이션이나 자잘한 에러는 찾아보기 바란다.

