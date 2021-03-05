inherit ROOM;
void create()
{
    set("short", "神农居");
    set("long", @LONG
神农尝百草，始有医药。百里零本为京城中官宦之家子弟，锦衣玉食，但天有
不测风云，某日朝中生变，诛百里一族，百里零幸在四处游玩未归，躲过一劫，于
仕途毫无兴趣，因其一向仰慕古时神农，又感其时众人多受疾病之苦，因此遍访名
川大泽，历尽穷苦之地，尝百草，著医术，救治众生。堂中悬匾一块： [33m

        		    恨不能尝天下草
                            叹无技救世间人
[32m
LONG
    );

    set("exits", ([
	"west"    	: __DIR__"swind5",
      ]) );
    set("objects", ([
	__DIR__"npc/baili" : 1,

      ]) );
    set("coor/x",20);
    set("coor/y",-240);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);

}
