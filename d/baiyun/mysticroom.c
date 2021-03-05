//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
        set("short", "石屋");
        set("long", @LONG
在白云岛如此有似仙境的人间天堂，这里却孤陋而狭小，四壁尽是厚厚的大岩石，
只有进来处的小门和对面石墙上一扇窄窄的铁窗，乍一看，自然会以为是囚禁犯人的
石牢，但奇怪的是，石屋里空荡荡的，除了一面硕大无朋的铜镜和一个很英俊的身穿
黄袍的年青人外，便别无一物。年轻人在镜子前来回踱着步，时不时停在镜子前做各
种各样的动作，或笑，或怒，或喜，或悲。。。
LONG
           );
        set("exits",
            ([
	    ]));
	set("objects",
 	   ([
        __DIR__"npc/southprince" : 1,
	    ]));
	    set("item_desc",	([
	    	"铁窗":		"铁窗虽然紧紧地关着，也许有可能撞开跳出去。(leave)\n",
	    	"window":	"铁窗虽然紧紧地关着，也许有可能撞开跳出去。(leave)\n",
	    ]));
	    
        set("indoors", "baiyun");
		set("no_fly",1);
		set("coor/x",0);
		set("coor/y",-1030);
		set("coor/z",0);
		setup();
}

void init()
{
	add_action("do_leave", "leave");
}

int do_leave()
{
	object me = this_player();
	
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你现在正忙。\n");

	tell_object(me,"你用尽全力，撞开密实的一扇铁窗，纵身跃了下去。 \n");
	
	tell_object(me,"石窗外赫然是汹涌的大海。 \n");
	tell_object(me,"你身子一沉，便什么也不知道了。。。 \n");
	me->unconcious();
	me->move(load_object(__DIR__"nujiao"));
//	me->revive();
	return 1;
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
