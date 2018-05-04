# aws bucket sync

aws cli를 설치해서 s3에 있는 파일 모두 다운받기(web에서는 버킷 전체를 다운받을수 없다)

```bash
// python and pip is required
$ pip install awscli
```

1. IAM 유저 생성 with S3 authorization
2. `AccessKey`와 `SecretAccesKey` 설정
3. `$ aws configure` 
```bash
AWS Access Key ID [None]: AccessKey
AWS Secret Access Key [None]: SecretAccesKey
Default region name [None]: ap-northeast-2
Default output format [None]: 
```
4. `$ aws s3 ls` 버킷이름 받아오기
5. `$ aws s3 sync localPath s3://bucketName` 
