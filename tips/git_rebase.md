# GIT rebase

깃에서 base를 바꾸는 명령지만 예전 커밋을 수정할 때도 사용할 수 있다. 이럴 경우 베이스가 바뀌므로 리모트 저장소에 올라간 커밋과 호환이 안될수도 있다.

git rebase -i #sha(git log로 확인해서 돌리기 전에 커밋 sha를 복사)
명령어를 실행할경우 editor에서 수정할 수 있는 커밋들의 목록이 나온다.
수정할 커밋을 edit으로 바꾼다음 :wq
여기서 수정한 다음 `git commit --amend`를 눌러서 커밋메세지를 수정한다(굳이 안해도됨)
`git rebase --continue`로 수정된 커밋을 모두 반영한다

만약 리모트 저장소에 올라가 있는 브랜치와는 호환이 되지 않는다.

`git push -u origin <branch_name> --force`

사용해서 완전히 덮어씌운다.
