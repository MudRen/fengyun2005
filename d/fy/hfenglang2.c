
inherit ROOM;

void create()
{
    set("short", "浣凰长廊");
    set("long", @LONG
这里是给到这儿的小姐们更衣入浴的，地上是五光十色的彩带和香味扑鼻的花
瓣，昂贵的衣裳满地都是，透过蒙蒙水雾，可以看到白腻的身躯，修长的大腿，坚
挺的胸膛，和乌黑的长发。。。。。。
LONG
    );
    set("exits", ([
	"north" : __DIR__"hfenglang1",
	"south" : __DIR__"hfenglang3",
      ]));
    set("no_magic",1);
    set("coor/x",-80);
    set("coor/y",-250);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);

}
