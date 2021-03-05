//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "烂柯草堂");
    set("long", @LONG
这里只是个破陋的草堂，没什么陈设；正堂上贴着一幅联子，但已破旧不堪，在
阵阵的海风中哗啦啦做响个不停，却怎么也不掉下来。上面书道：《水经注》云：信
安有悬室坂，晋中朝时，有民王质伐木至石室中，见童子四人弹琴而歌，质因倚柯听
之。。童子云：汝来已久，可还。质取斧，柯已烂尽，便归家，计已数百年。真所谓：

               局上闲争战        人间任是非
               空叫禾樵客        烂柯不知归

LONG
    );
    set("exits",
      ([
	"east" : __DIR__"skystreet3",
      ]));
    set("objects",
      ([
	__DIR__"npc/zhongpu" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",-20);
    set("coor/y",-160);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
