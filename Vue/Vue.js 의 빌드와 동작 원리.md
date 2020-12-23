# Vue.js 의 빌드와 동작 원리

2020 12 23

Vue 프로젝트에서 개발자가 프론트 엔드로 개발을 마쳤다. 그 다음으로 해야할 일이 빌드를 하고, 배포를 해야 한다. 뭐 개발하면서 빌드 여러번 해봣을 거지만.. 배포는 안해봤을 것이다!!. `npm run dev` 이런 식으로 프로젝트를 실행시켜서 로컬에서만 결과를 확인했을 것이다!!!

나도 아직 NGinx 나 Apache, Gitlab Runner 이런 것들을 써본 적은 있어도 동작 원리나 자세한 것들은 잘 모르지만.. 차근차근 알아가보려 한다. 먼저 Vue 프로젝트를 어떻게 빌드하는지부터 알아보려 한다. 아니. 빌드하는 방법은 나와있으니까, 빌드가 되는 원리부터 알아보려고 한다.

---

### npm & package

package.json 파일에서 Vue 프로젝트의 이름, build 나 run scripts등을 설정할 수 있다.

필수 모듈들을 설치할 때 `npm install` 이라는 명령어를 사용하게 되는데, 

1. --save 명령어 : 현재 프로젝트의 node_modules에 설치가 되며, 빌드와 실행시에 사용이 된다.
2. --save-dev 명령어 : 현재 프로젝트의 node_modules 에 설치가 되고, 빌드시에만 사용된다. 

---

### app.js

Vue 에서  /src/app.js 파일은 `Entry Point` 이다. 따라서 Vue 프로젝트를 실행시키고 맨 처음 들어가는 곳이 app.js 파일인 것이다.

app.js

```javascript
import Vue from 'vue'
import App from './App.vue'
new Vue({
  el: '#app',
  render: h => h(App)
})
```

---

### Webpack

Javascript 파일들이 프로젝트에 너무 많아져서, 관리하기가 매우 어렵다. 이 수많은 javascript 파일들을 따로 따로 import 하고 require해서 관리를 할 수도 있지만, 여러 개의 파일을 한 페이지에 로딩해야 하는 일이 많기 때문에 상당히 골치가 아픈 일이다.

따라서 이 수많은 Javascript 파일들을 하나의 파일로 관리하기 위해 Webpack이 등장하게 되었다.

- Webpack은 Static Module Bundler이다.
- Webpack이 실행되면 Dependency graph를 통해 하나 또는 여러 개의 Bundle을 생성한다.
- Webpack은 Javascript와 Json만 지원한다.
- ES5를 사용하는 모든 브라우저를 지원한다.

#### Entry

- Webpack 의 Entry는 ./src/index.js 이다
- 여러개의 Entry가 존재할 수도 있다.

#### Output

- Webpack이 생성한 bundles의 결과물이다.
- Default 값은 ./dist/main.js 에 생성이 된다.

#### Loader

- 다른 Type의 파일을 이해하고 처리가능한 모듈로 변환시키는 작업을 한다.



Webpack 빌드 환경을 구성하고 빌드를 하면 된다.

---

### 빌드

Terminal 창에서 

```bash
$ npm run build
```

커맨드를 입력하게 되면, 

`\  Building for production...` 표시가 나오면서 빌드가 된다. Vue 프로젝트는 Default로 /dist 디렉토리 아래에 빌드된 결과물이 생성된다. 이것이 Webpack으로 빌드한 것이다.

![image](https://user-images.githubusercontent.com/28242038/102968430-33d44800-4537-11eb-9f7f-d10e50c58f9a.png)

대략 이런 식으로 생긴다.

---

### 참조

https://nesoy.github.io/articles/2019-02/Webpack

https://skypacific.github.io/2019/02/25/kang.heehun@buildup_vuejs.html



#### 더 찾아보기

https://jay-ji.tistory.com/57

https://jay-ji.tistory.com/58?category=870634

https://k39335.tistory.com/64