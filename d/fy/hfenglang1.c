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
	"north" : __DIR__"hfeng",
	"south" : __DIR__"hfenglang2",
      ]));
    set("coor/x",-80);
    set("coor/y",-245);
    set("coor/z",0);
    set("map","fysouth");
    setup();
}


/*
int valid_leave(object me, string dir)
{
    if(  dir == "south" && me->query("gender") != "女性")
	return notify_fail("这是女人浴室，你冲进去作什么？\n");
    return 1;
}
*/