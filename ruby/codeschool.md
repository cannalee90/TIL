#Code School Ruby bits



###기본

- 루비에서는 "", 0, []는 boolean expression에서 true와 같다
- ture가 아닌 경우는 false일 때만
- if 문일때 대입하는 경우는 주로 nil block을 사용해서 작성한다

~~~
options[:country] = us if options[:country].nil?
options[:countyr] ||= 'us'
~~~

- conditional return values를 작성할대는 다음과 같이 작성한다

~~~
if list_name
  options[:path] = '/asset/js'
else
  options[:path] = '/asset/none'
end
=========
options[:path] = if list_name
  '/asset/js'
else
  'asset/none'
end
~~~

이런 방식은 case문에도 사용할 수 있다
~~~
client_url = case client_name
  when "web"
    "twitter"
  when "Facebook"
    "FB"
  else
    nil?
end
~~~

Case Range문은 다음과 같이 상용한다

~~~
popularity = case tweet.retweet_count
  when 0..9
    nil?
  when 10..99
    "trending"
  else
    "hot"
end
~~~

Case문을 한줄로 바꿔서 사용할 수도 있다

~~~
tweet_type = case tweet.status
  when /\A@\w+/ then :mention
  when /\A@\w+/ then :direct_message
  else               :public
end
~~~

- 함수를 만들때 optional argument의 default 값을 정해줄 수 있다. 만약 이렇게 argument의 값을 정해주게 되면 parameter를 넘겨주지 않을 수도 있고 parameter 값을 넘겨주지 않은 default 값이 설정된다.

~~~
def tweet(message, lat = nil, long = nil)
end

tweet("Practicing Ruby-fu")
~~~

- 또한 argument가 더욱 더 많아질 경우에는 hash argument를 사용해주면 된다. 이때 hash_argument의 값은 모두 optional하다

~~~
def tweet(message, options = {})
  status = Status.newline
  status.lat = options[:lat]
  status.long = options[:long]
  status.reply_id = options[:reploy_id]
  status.post
end

tweet("Ruby", last: "hi"
  long: "-18"
  reploy_id: 21221
)
~~~

또한 splat method를 사용해서 여러 parameter로 넘긴 인자를 하나의 argument로 받을 수도 있다.

~~~
def metion(*msg)
  puts msg[0]
  puts msg[1]
  puts msg[2]
end

metions('hi', "hello", "world")

> hi
> hello
> world
~~~

클래스에서 인스턴스 변수에 대해서 getter와 setter를 세팅하는 간결한 방법은 attr_accessor를 사용한다. 만약 setter를 셋팅하기 싫으면 attr_reader를 사용한다.

ruby에서 this와 비슷한 개념의 예약어는 self이다

- 루비에서 to_s는 모든 객체에서 정의되어 있으며 항상 무언가를 리턴한다.
- 루비에서 to_str은 스트링같은 비슷한 객체에만 정의되어있다(symbol은 to_str이 정의 되어있지만 Array는 to_str이 정의되어 있지 않다.
