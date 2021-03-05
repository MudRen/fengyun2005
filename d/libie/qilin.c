// Room: qilin.c --- by MapMaker
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "麒麟阁");

	set("long", @LONG
所谓麒麟阁，其实只是一间很宽阔的屋子，四壁雪白无尘，用红木铺成的地面，
盖了层厚实贵重的绣花地毯。屋子里什么都没有，只有两个蒲团。
LONG);

	//{{ --- by MapMaker
	set("type","indoors");
	set("exits",([
		"out":__DIR__"corridor2",
	]) );
	//}}
	set("indoors", "libie");
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",30);
        set("no_fly",1);

	setup();
}

void init(){	
	add_action("do_kill","kill");
}

int valid_enter(object me)
{
	object ying,yang,di;
	object room;
	
	room=this_object();
	room->reset();
	set("结局人物",me);

	if (objectp(di=present("di qinglin",room)))
			destruct(di);
	if(!objectp(di=present("di qinglin",room)))
	{
		di=new(__DIR__"npc/diqinglin");
		di->move(room);
	}
	if(!objectp(ying=present("ying wuwu",room)))
	{
		ying=new(__DIR__"npc/yingwuwu");
		ying->move(room);
	}
	ying->start_call_out( (: call_other, ying, "do_busy", me :), 1);	
	if(!objectp(yang=present("yang zheng",room)))
	{
		yang=new(__DIR__"npc/yangzheng");
		yang->move(room);
	}
	yang->start_call_out( (: call_other, yang, "do_rival", di :), 1);			
	return 1;
}

int do_kill(string arg)
{
	object me,yang,di,ying,room;
	
	room=this_object();
	me=this_player();
	if(!present(arg,room)) return 0;

	if(present("yang zheng",room)&&present("di qinglin",room))
	{
		write(HIW"你被狄杨两人的杀气所慑，居然一动也没法动。\n"NOR);
		return 1;
	}
	return 0;
}

int valid_leave(object me,string dir)
{
	object yangcorpse;
	
	if(dir!="out") return 1;
	if(query("结局人物")) delete("结局人物");
	if(present("di qinglin",this_object()))
		return notify_fail(HIR"狄青麟微笑的对你说：“这就走？用不着那么急吧？”\n"NOR);
	if(me->query("libie/离别钩_杀死狄青麟")==1)
	{	
		if(objectp(yangcorpse=present("yang's corpse",me)))	
			return 1;
		if(present("yang's corpse",this_object()))
			return notify_fail(HIY"你看着杨铮死不瞑目的尸体，觉得放在这里未免于心不忍。\n"NOR);
	}
	return 1;
}
