1. jetson_dxl
패키지에서 publisher 노드의 기능을 수행하는 패키지를WSL2에서 작성하라.
섭스크라이버 노드는 예제1번 패키지를 그대로 사용하라.
+ pc 는 pub_wsl, jetson은 sub 노드만 사용한다.(pc부분 sub 무시, jetson부분 pub_wsl 무시 __ 연습장)
+ 패키지명 : dxl_wsl
+ 퍼블리셔노드 : pub_wsl.cpp


2. camera 패키지를 이용하여 카메라 영상을 WSL2에서 출력하고 동시에 동영상 파일로 저장한다.
   그리고 예제 1번의 dxl 패키지를 이용하여 영상을 보면서 로봇을 제어해보시오.
+ 강의실 앞쪽에서 책상사이를 통과하여 뒤쪽까지 주행하고 다시 출발위치로 돌아오도록
  제어하고 전과정을 동영상 파일로 저장할 것
+ pc 는 pub_wsl, jetson은 sub 노드만 사용한다.(pc부분 sub 무시, jetson부분 pub_wsl 무시 __ 연습장)

