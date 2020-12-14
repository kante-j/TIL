# Python기초문법 - 입출력

2020 12 13

조건문, 반복문, 함수는 C++이나 JAVA와 크게 다르지 않아서 간단히 눈으로 보고 넘어가기로했다. 

- 연산자 부분은 `x and y` 형태로 `&&` 를 사용하지 않았고, or 도 마찬가지였다. List 안에 x가 들어있는지를 알아보려고 할 때는 `x in List` 형태로 사용하면 된다. 

- 반복문 같은 경우에는 while, for 두 가지가 잇는데 `while i<=10:` 형태로 사용을 하면 되고, for 문은 `for i in rnage(0,10):` 형태로 사용을 하면 된다. in 뒤에 오는 데이터는 리스트, 튜플, 문자열 등이 사용된다.

- 함수는 `def 함수이름(매개변수)` 으로 함수를 선언할 수 있다.

  ```python
  def add(a,b):
    return a+b
  ```

- 마지막으로 파이썬에서는 람다 표현식을 사용할 수 있다. 

  ```python
  print((lambda a, b: a+b(1,5))) # add() 메서드를 람다표현식으로 표현
  ```

---
이렇게 파이썬 기초 문법을 간단히 보고, 입출력에 대해서 조금 자세하게 보도록 했다. 파이썬 문법을 공부하는 것은, 기업 코딩테스트에서 문자열이 많이 나오는데, 파이썬으로 하면 문자열 부분을 처리하기 매우 쉽기 때문이다.

### 입력

- `10 30 90 70 50` 과 같은 리스트를 파이썬에서 입력을 받으려면

  ```python
  li = list(map(int, input().split()))
  print(li) # 10 30 90 70 50
  ```

- `10 30 50` 을 각각 a,b,c에 입력을 받으려면

  ```python
  a,b,c = map(int,input().split())
  print(a) # 10
  print(b) # 30
  print(c) # 50
  ```



문제를 풀다보면 입력 부분에서 시간초과가 나는데, C++에서 입력을 빠르게 받으려면

```c++
int main(){
  ...
  cin.tie(0);
  scanf("%d",&a);
  ...
}
```

cin.tie를 사용하거나, scanf를 사용해서 입력을 받는다. 파이썬에서는

```python
import sys
a = sys.stdin.readline().rstrip() # Hello World 입력
print(a) # Hello World
```

로 입력을 받으면 된다.

### 출력

출력을 할 때, 줄바꿈을 하지 않으려면,콤마를 사용해서 출력하면 된다.줄바꿈을 하려면 print 함수를 두 번 써도 된다.

```python
a,b = (1,2)
print(a,b) # 1 2
```

하지만 이 int형 변수를 string 변수와 함께 출력을 하려면 에러가 나는데, 이를 해결하기 위해서는 str()로 형변환을 해주면 된다.

```python
a=2
print("number : " + a) # 에러
print("number : " + str(a)) # number : 2
```

Python 3.6 이상 버전부터 f-string 문법을 사용 할 수 있다.

```python
a = 2
print(f"number : {a}") # number : 2
```

---

다음에는 알고리즘 문제를 풀 때 필요한 heap이나 queue, 등을 알아볼 것이다.

  