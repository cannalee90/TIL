# Chromless

chromless를 사용하기 위해서는 로컬 혹은 원격에 있는 크롬이 필요하다. 원격에 있는 크롬을 사용할때 우리가 직접 빌드한 headless chrome이나 혹은 이미 잘 빌드된 headless chrome을 aws 람다 펑션에 올려서 사용할 수 있다.

```
{
    "Version": "2012-10-17",
    "Statement": [
        {
            "Sid": "Stmt1449904348000",
            "Effect": "Allow",
                "Action": [
                "cloudformation:CreateStack",
                "cloudformation:CreateChangeSet",
                "cloudformation:ListStacks",
                "cloudformation:UpdateStack",
                "cloudformation:DescribeChangeSet",
                "cloudformation:ExecuteChangeSet",
                "cloudformation:DescribeStackResource",
                "cloudformation:DescribeStackEvents",
                "cloudformation:ValidateTemplate",
                "iam:CreateRole",
                "iam:PutRolePolicy"
            ],
            "Resource": [
                "*"
            ]
        }
    ]
}
```

위 정책을 추가한 다음 `lambda` `s3` `api gateway` `IoT` 정책이 필요 하다. 사실 필요없을 수도 있긴 하지만 이때 원래 있던 cloudformation stack이나 lambda 함수 혹은 s3 버킷이 있으면 제대로 동작하지 않으니까 다 지우는게 중요하다.

chromeless를 proxy로 배포했을 경우 payload가 128kb를 넘어갈 경우 문제가 생긴다.

이 제한을 생각해서 구현해야 한다.

https://github.com/prismagraphql/chromeless/issues/114