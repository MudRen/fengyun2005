// Room: darklane2.c --- by MapMaker
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "暗巷尽头");

	set("long", @LONG
小巷又窄又暗，一阵阵又湿又冷的风似鬼魂般时有时无，你不禁打了个寒战。
血腥之气弥漫在空气之中，一种莫名的恐怖，强烈的恐怖，梦魇般压住了你的心
头。血，遍地的血；尸骸，残缺的尸骸……耳边突然传来的一声声野兽般的呻吟，
一股针尖般的寒意刺透了你的骨髓，刺透了你的心。
LONG);

	set("type","street");
	set("exits",([
	"south":__DIR__"darklane1",
	]) );

    	set("objects", ([
        	__DIR__"npc/huzi" : 1,
    	]) );
        set("indoors", "libie");
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_heal","heal");
}


int do_heal(string arg)
{
    	object me, ob, ob1, ob2;
    	me = this_player();
    
    	ob = present("huzi", this_object());
    	ob1 = present("snow lotus", this_player());
    	
        if( !ob || userp(ob)) return 0;
        if( !arg || (arg != "xiao huzi"&&arg!="huzi" &&arg!="小虎子")) return notify_fail("你要救谁？\n");
        if( !ob1 && !ob2 ) return notify_fail("两手空空就想救人？\n");
        
        if (ob1)
        if (ob1->query("owner")) {
        	ob->ccommand("say 啊啊啊啊，你想作弊，名字我记下了。");
        	return 1;
        } 
        
        if( me->is_busy()) return notify_fail("你上一个动作还没有完成。\n");
        
        if( !ob->query_temp("is_unconcious")) 
        	return notify_fail("人醒着呢！\n");
        if(ob1)
        {
            	message_vision(HIG"$N托着小虎子的下巴，将一株天山雪莲小心翼翼地送入他口内！\n"NOR,this_player());
            	destruct(ob1);
        }
        
	ob->revive();
	ob->set("救人者",me);
	return 1;
}
