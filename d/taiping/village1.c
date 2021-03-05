#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "前院");
        set("long", @LONG
前院实则是一片大草坪，草坪中央，有一座喷水泉，用白大理石筑成，上面镂
着精致的雕刻。一尊石像，由圆座托着，矗立在池子中心，把水花喷射到半空。庄
园的正门紧紧关闭着，左侧有一扇供下人进出的[33m边门[32m。由前院往里，白玉般的三重
石阶尽处，一座大堂。大堂中灯火通明，光如白昼。
LONG
        );
        set("exits", ([ 
		"south": __DIR__"village2",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		"door": "大门关的死死的，左侧的边门似乎可以推开。\n",
		"门": "大门关的死死的，左侧的边门似乎可以推开。\n",	    
		"边门": "大门关的死死的，左侧的边门似乎可以推开。\n",	    
	]));
	set("coor/x",70);
	set("coor/y",-40);
	set("coor/z",0);
	set("map","taiping");
	setup();
}

void init()
{
       	add_action("do_push", "push");
}


void close_passage()
{
        object room;
        message("vision", "边门无声无息地又关上了。\n", this_object() );
        delete("exits/north");
}

int do_push(string arg)
{
        object obj, room;
        if(!arg || (arg != "边门" && arg != "door" && arg !="门")) {
                return 0;
        }
		if (query("exits/north"))
		return notify_fail("边门已经打开了。\n");
		message_vision(WHT"$N用力一推，吱呀一声边门打开了。\n"NOR, this_player());
		set("exits/north",__DIR__"gate");
        call_out("close_passage", 10);
        return 1;
}


void reset()
{
        ::reset();
        delete("exits/north");
}