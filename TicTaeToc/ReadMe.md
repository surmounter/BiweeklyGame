
# 목차

* [TicTacToeGate](#TicTacToeGate-클래스)
* [MVC 패턴](#MVC-패턴)
  * [TicTacToeController](#TicTacToeController-클래스)
  * [TicTacToeModel](#TicTacToeModel-클래스)
    * [TicTacToeBoard](#TicTacToeBoard-클래스)
    * [TicTacToeMissionMessageSet](#TicTacToeMissionMessageSet-클래스)
  * [TicTacToeView](#TicTacToeView-클래스)



# MVC 패턴

![ttt1](img/ttt1.png)

## TicTacToeGate 클래스
* 사용자가 이벤트를 발생시키면, 그에 대응되는 `TicTacToeController`에 있는 함수를 호출해줍니다.

## TicTacToeController 클래스
* MVC 패턴에서 Controller에 해당하는 부분이다.
* 들어오는 이벤트에 맞게 Model의 멤버변수를 업데이트한다.
* Model의 멤버변수를 조회해서 View에 전달하여 그래픽을 업데이트한다.

## TicTacToeModel 클래스

![ttt2](img/ttt2.png)

* MVC 패턴에서 Model에 해당하는 부분이다.
*  `TicTacToeMissionMessageSet`에서 미션메시지를 가져오고, `TicTacToeBoard` 클래스를 업데이트하며, `TicTaeTocAudioMgr` 클래스를 통해서 사운드를 발생시킨다.

### TicTacToeBoard 클래스
* 3x3 board를 전반적으로 관리한다. 
* 3x3 board에서 한 Slot에 말을 놓을 수 있다면, 말을 놓는 함수를 제공한다.
* 3x3 board에 놓여있는 말의 상태를 보고, 승리조건을 만족하는 플레이어가 있는지를 판단하는 함수를 제공한다.

### TicTacToeMissionMessageSet 클래스
* 플레이영상을 보면, 말을 놓을때마다 미션이 팝업창에 뜨면, 미션을 완료한 경우에만 말을 놓을 수 있다. 실패한 경우에는 말을 놓을 수 없으며 턴이 상대에게 넘어간다.
* `TicTacToeMissionMessageSet` 클래스는 팝업창에 뜨는 미션을 관리하는 클래스이다.
* `Resource/missionMessageFile.txt`에 기록되어있는 미션목록들을 파싱해서 자료구조에 저장해둔다.
* 미션목록에서 랜덤으로 미션을 반환하는 함수를 제공해준다.

## TicTacToeView 클래스

![ttt3](img/ttt3.png)

* MVC 패턴에서 View에 해당하는 부분이다.
* `TicTacToeController`클래스를 통해서 `TicTacToeModel`의 3x3 board 현황을 저장해둔 자료구조를 값복사받아서, 이를 가지고 그래픽을 업데이트한다.
