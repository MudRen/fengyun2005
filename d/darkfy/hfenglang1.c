
inherit ROOM;

void create()
{
        set("short", "长廊");
        set("long", @LONG
这里是给到这儿的小姐们更衣入浴的，地上是五光十色的彩带和香味扑鼻的花瓣,
昂贵的衣裳满地都是，透过蒙蒙水雾，你可以看到白腻的身躯，修长的大腿，坚挺的
胸膛，和乌黑的长发。。。。。。
LONG
        );
        set("exits", ([
                "west" : __DIR__"hfeng",
		"north" : __DIR__"hfenglang2",
        ]));
        set("coor/x",21);
        set("coor/y",30);
        set("coor/z",-300);
        setup();
}


