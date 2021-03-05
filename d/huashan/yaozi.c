
inherit ROOM;

void create()
{
    set("short", "鹞子翻身");
    set("long", @LONG
此处崖壁直立，看似无道路可行，但仔细观，有几个脚窝凿于悬崖之上，一条
铁索垂于凌空，不见路径。至此，须面壁挽索，以脚尖探寻石窝，交替而下。其中
几步须如鹰鹞一般、左右翻转身体才可通过，故名。由此向南便是下棋亭。
LONG
    );
    set("exits", ([ 
	"northwest" : __DIR__"chaoyang",
	"south" : __DIR__"qipan",
      ]));

    set("outdoors", "huashan");

    set("coor/x",-1);
    set("coor/y",-56);
    set("coor/z",33);
    setup();
}

/*
int valid_leave(object who,string dir){
    int i;

    i = who->query_cor();
    if(dir=="south" && i < 15){
	message("vision",who->name() + "望着石崖上的路，摇了摇头。\n" 
			, this_object(), who);
	return notify_fail("你望着眼前的路，不由得有些却步。\n");
	}
    return 1;
}
*/
