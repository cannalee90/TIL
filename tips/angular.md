```html
<ng-container *ngIf='kangho$ | async'>
</ng-container>
```

1. 변수를 굳이 많이 사용할 필요 없다.
2. 공용으로 사용되는 로직은 모델이나 서비스에서 작성한다.