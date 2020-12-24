# Babel

🎄2020 12 24🎄

(윈도우에서 이모지 단축키가 Windows + . 이래요 ㅋㅋ)

React나 Vue를 공부하다가 보면 `Babel`이란 단어를 못 들어봤을 수가 없다. Babel은 어떤 역할을 하고 왜 필요한지 알아보자

---

### 필요한 이유

ES6(ECMA Script는 자바스크립트의 표준이며 코어임) 이나 그 이상 버전을 사용해서 빌드 프로젝트를 진행하려면 개발 환경 구축을 잘 해야한다.

React를 개발할 때 

```javascript
const foo = require('foo')
```

같이 사용하는 걸 본 적도 있고

```javascript
import foo from 'foo'
```

같은 것도 본 적이 있을 것이다. 하지만 만약에 자바스크립트 버전이 맞지 않다면 아래의 코드는 사용할 수가 없을 것이다.

정리하자면

Babel은 최신의 자바스크립트 코드를 이전 단계를 자바스크립트 코드로 변환 가능하게 해주는 도구이다. ES6+로 작성된 코드를 IE나 아니면 모든 브라우저에서 문제 없이 작동하게 하려면 Babel을 사용하면 된다. 즉 **호환성** 을 위해 존재한다.

#### Babel 기능

- 구문 변환
- Polyfill 기능
- 소스코드 변환

---

### ES6

ES6 는 ES5에 비해서 상당히 많이 바뀌었다. 코딩에 유용하게 바뀌었는데, 간단한 몇 가지만 살펴보면

#### Arrow Function

```javascript
arr.forEach(item => {
    console.log(item)
})
```

함수 선언을 매우 간단하게 할 수 있다.

#### Classes

자바스크립트는 프로토타입 기반 언어라 클래스가 존재하지 않는다. 하지만 ES6 부터는 프로토타입을 클래스처럼 구현하여 사용할 수 있게 되었다.

#### let, const

원래는 var을 사용했었지만, ES6 부터는 수정 가능한 변수는 let, 불가능한 변수는 const이다.(Swift에서는 let이 수정 불가능.. 아 헷깔려) 

---

### 참조

https://brunch.co.kr/@topherlee/29