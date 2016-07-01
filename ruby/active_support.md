## Active Support

###Definision

- ROR의 구성요소중 하나로써 루비 언어를 좀 더 풍부하게 만들고 사용하기 쉽게 만들어준다.
- It offers a richer bottom-line at the language level, targeted at the development of Rails applications, and at the development of Ruby on Rails it self.

~~~
require 'active_support'
require 'active_support/core_ext/object/blank'

object의 blank method만 불러오게 된다.

require 'active_support'
require 'active_support/all'

모든  active_support를 불러오게 된다
~~~

###Extension to All Objects

#### blank? and present?
  - 다음과 같은 값들은 레일즈 어플리케이션에서 blank와 같은 취급을 받는다
    1. nil and false
    2. whitespace로만 이루어진 문자열
    3. empty arra와 hash
    4. empty?에 해당되는 모든 객체들
    5. 0이나 0.0은 blank에 해당되지 않는다.

#### presence
  - presence method는  object.blank?의 값이 참일 경우 nil을 리턴하고 그렇지 않을 경우 객체의 값을 리턴한다.

~~~
"aaaa".presnece
> aaaa

"\n\n\t\t".presence
> nil
~~~

#### duplicable?
- 루비의 기초적인 몇개의 객체들(숫자 1,이나 true)들은 전체 프로그램안에서 하나의 객체들을 참조하게 된다. 이러한 객체들은 복사가 불가능하다. Active Support에서 제공하는 duplicable?이라는 method를 사용해서 그러한 속성을 밝혀낼 수 있다.

~~~
"foo".duplicable?
> true
1.duplicable?
> false
false.duplicable?
> false
~~~

#### deep_dub
- 루비에서는 기본적으로 dub method 혹은 = 사용해서 값을 복사를 하게 되면 얕은 복사 방식으로 이루어지게 됩니다. 그러한 방식을
