Get Next Line (8.13~)

목표: line을 file descriptor로부터 읽어 줄바꿈과 함께 리턴하는 함수를 만든다.
- 이를 통해 나의 collection에 매우 편리한 함수를 추가할 수 있을 뿐만 아니라,
- C 프로그래밍의 매우 흥미로운 새로운 개념인 static variable(정적 변수)에 대해 학습한다.

<Mandatory part>

함수 이름		get_next_line
프로토타입	int	get_next_line(int fd, char **line);
제출할 파일	get_next_line.c, get_next_line_utils.c, get_next_line.h
파라미터		#1. 읽어올 파일 디스크립터
			#2. 읽어진 값
리턴값		1: line이 읽어짐
			0: EOF(End-of-File, 파일 끝)에 도달함
			-1: 에러 발생

- get_next_line 함수를 loop안에서 호출하면, 파일 디스크립터의 텍스트를 한줄씩 읽어오게 된다.
(EOF에 도달할 때까지)
- 파일로부터 읽어올 때와 표준 입력으로 읽어올 때 모두 잘 작동하는지 확인한다.
- libft는 사용 불가. 필요한 함수들이 추가된 get_next_line_utils.c 파일을 추가해야 한다.
- 컴파일: gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
- flag -D BUFFER_SIZE=xx.
Buffer size는 평가자와 moulinette에 의해 수정될 수 있다.
- read는 BUFFER_SIZE를 이용해야 한다.
- get_next_line.h 헤더파일에 최소한 get_next_line 함수의 프로토타입은 있어야 한다.

! BUFFER_SIZE 값이 1, 9999, 1000000에서 작동하는가? 이유는?
! get_next_line이 호출될 때마다 가능한 조금씩만 read될 수 있게 해야한다.
	newline에 맞닥뜨리면 current line을 리턴해야한다.
	(전체 파일을 다 읽은 다음 각 라인을 처리해서는 안된다)
! 파일/redirection/표준 입력 등에서 읽어오는 테스트를 해본 후 제출한다.
	표준 입력에 newline을 전달하면 어떻게 작동하는가? CTRL-D를 하면 어떻게 작동하는가?

- 




