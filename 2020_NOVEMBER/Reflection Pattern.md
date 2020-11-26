# Reflection 패턴

2020.11.25

PHP를 보다가 ReflectionClass라는 것이 나와서 찾아보게 되었다.

PHP Manual Page에는 `The ReflectionClass class reports information about a class.` 라고 나와있다.

"ReflectionClass 클래스는 클래스에 대한 정보를 보고한다" 라는 말이다.

---

#### 리플렉션

> 오브젝트에 대한 구체적인 클래스 정보 없이도, 오브젝트가 가진 변수나 메소드 등에 접근할 수 있게 하는 것

자바에서의 리플렉션이 가장 큰 특징이라 했으므로, 자바 코드로 한 번 봐야겠다. 클래스가 가진 모든 멤버의 이름을 얻거나 보여줄 수 없고, 자바 클래스가 그 자신을 조사하고 수정하는 것이 다른 언어에서는 볼 수 없다.

```java
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
public class BigA{
    public static class A{
        int a = 1;
        public int getA(){
            return a;
        }
    }
    public static void main(string[] args) throws NoSuchMethodException, InvocationTargetException, IllegalAccessException{
        Object a = new A();
        a.getA(); // 에러
        Method getA = A.class.getMethod("getA"); // 가능
    }
}
```

Object a 로 선언을 했을 때, Object타입이 뭔지 모르기 때문에 getA메소드를 바로 호출할 수는 없다.

Method라는 리플렉션으로 getA메소드를 불러온 후 사용할 수 있다.



### 장단점

|          장점           |               단점               |
| :---------------------: | :------------------------------: |
| 소스코드 임의 수정 불가 | 컴포넌트의 개수가 증가할 수 있음 |
|   시스템 변경이 쉬움    |         효율성이 떨어짐          |
| 다양한 종류의 변경 지원 |     모든언어가 지원하지 않음     |





---

참고

1. http://software-pattern.org/Reflection

2. https://meaownworld.tistory.com/92