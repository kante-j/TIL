# Laravel Vue를 같은 프로젝트에서 만들 때 "cannot find element #app" 가 보인다면

2020 12 18

Vue를 Laravel 프로젝트 내부에서 `npm run watch` 형식으로 보면서 개발하는 방법은 인터넷에 찾아보면 많이 나올 것이다. 그러나, `cannot find element #app` 이라는 에러가 나는 계속해서 나왔고, 왜 이런지 도저히 알 수가 없었다.

> [Vue warn]: Cannot find element: #app

이게 app이라는 id를 못 찾아서 id가 app인 DOM으로 바인딩을 못 시켜준다는건 이해하겠는데, 왜 이걸 못찾지?? 계속 찾아보았다.

Laravel에서는 blade.php 파일로 Template View를 나오게 하고 있었으며, 여기에다가 내가 보여줄 파일을 나오게 해야 했다.

이곳에서 내가 App.vue 파일을 뿌려주어야 했는데,

```html
<html lang="en">
    <head>
        ...
        <script src="{{ asset('js/app.js') }}"></script>
    </head>
    <body>
        <div id="app"></div>
    </body>
</html>
```

이렇게 js/app.js 파일을 불러와서 해도 되지가 않아서 엄청나게 헤맸다. 그러다가 

[구원의 링크](https://laracasts.com/discuss/channels/vue/vue-cannot-find-element-app) 여기서 맨 아래에 

```html
<-- <script src="{{ asset('js/app.js') }}"></script> 를 아래로 변경-->
<script src="{{ asset('js/app.js') }}" async defer></script>
```

async defer 키워드를 추가해주라는 것을 해보았는데.. 됐다!! 잘보인다.

이제 Vue와 다른 백엔드 시스템을 따로 개발하지 않아도 된다!!