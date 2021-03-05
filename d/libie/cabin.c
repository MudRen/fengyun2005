// Room: cabin.c --- by MapMaker
#include <ansi.h>
inherit ROOM;


int resleep(object ob);
void create()
{
	set("short", "小木屋");

	set("long", @LONG
这是间破旧而简陋的小木屋，但收拾的干干净净。木屋里只有一床一桌一椅，
几个粗碗，一盏瓦灯和一个红泥的火炉，每样东西都很破旧。床上一个疲倦不堪
的中年女子象孩子一般静静睡着。桌子上摆了几碗饭菜，筷子旁边压着张纸笺。
LONG);

	//{{ --- by MapMaker
	set("type","house");
	set("exits",([
	"south":__DIR__"woodsedge",
	]) );
	
	set("objects", ([
        __DIR__"npc/lusuwen": 1,
        ]) );
        set("indoors", "libie");
	set("no_fight",1);
	set("no_fly",1);
	set("coor/x",20);
	set("coor/y",40);
	set("coor/z",0);
	
	//}}

	setup();

}


void init()
{
    add_action("do_look","look");
}


int do_look(string arg)
{	
    	object lusuwen, me;
    
    	me=this_player();
    
    	if (arg=="桌子"||arg=="table")
    	{
        	tell_object(me,"
一张破旧但很整洁的桌子，上面摆着两碗饭，一盆青菜，一碟霉豆腐，一碗腊肉，
两双筷子整齐的摆在饭碗旁边。饭菜都一点没有动过，如果不是已经冷掉了的话，
简直就象刚刚端上桌来的样子。其中一副碗筷的旁边，放着一个小酒壶，酒壶的
旁边有一张纸笺。\n");
    		return 1;
    	}
    	
    	if (arg=="纸笺"||arg=="sheet")
    	{
        	tell_object(me,GRN "一张淡雅的纸笺，上书：
    	
杨铮吾郎：

铮郎已去三日，不归。妾先小憩，桌上饭菜亦候三日。但望与铮郎共食。

                                                     素文\n"NOR,this_player());
        	return 1;
    	}
    
    	if (lusuwen=present("lu suwen",this_object()))
    	if (!living(lusuwen))    
    	if (lusuwen->query("disable_type")==HIG"<睡梦中>"NOR)
    	if (arg=="吕素文"||arg=="lu"||arg=="lu suwen")
     	{
        	tell_object(me,"吕素文甜梦正酣，但似乎可以唤醒（ｗａｋｅ）的样子。\n");
   		add_action("do_wake","wake");     	
   	}
    	
    	return 0;
}

int do_wake(string arg)
{
	object ob,me;
	
	if(!arg) return 0;
	ob=present(arg,this_object());
	me=this_player();
	if(!ob) return notify_fail("这里没有这个人。\n");
	if(ob->query("id")=="lu suwen")
	{
		remove_action("do_wake","wake");
		ob->start_call_out( (: call_other, ob, "wake" ,me:), 0);
		if(me->query_temp("libie/离别钩_准备送饭") && present("hot rice",me)
				&& present("hot greens",me) && present("hot soup",me)
				&& !REWARD_D->riddle_check(me,"离别")) 
		{
			ob->start_call_out( (: call_other, ob, "ask_question" ,me:), 3);
		} else if (REWARD_D->riddle_check(me,"离别")==3)
		{
			ob->start_call_out( (: call_other, ob, "give_sword" ,me:), 3);
		}
	//	else
	//	{
			ob->start_call_out( (: call_other, ob, "sleep" :), 20);
	//	}
		return 1;
	}
	return 0;

}

int valid_enter(object me)
{
	object lu,yang;
	int finale;

	if(lu=present("lu suwen",this_object())) 
	if(finale = me->query("libie/离别钩_杀死狄青麟"))
	{
		if(finale==1)
		{
			set("结局1人物",me);
			me->set_temp("libie/离别钩_目睹最后结局",1);
			if(!living(lu))
				lu->start_call_out( (: call_other, lu, "wake" ,me:), 2);		
			lu->start_call_out( (: call_other, lu, "dying", me:), 5);		
	
		}
		if(finale==2)
		{	
			set("结局2人物",me);
			me->set_temp("libie/离别钩_目睹最后结局",1);
			yang=new(__DIR__"npc/yangzheng2");
			yang->move(this_object());
			lu->die();
			me->start_call_out( (: call_other, yang, "dying" ,me:), 3);
		}
	}
	return 1;
}	

int valid_leave(object me,string dir)
{
	if(me->query_temp("libie/离别钩_目睹最后结局"))
		return notify_fail("你想离开，但鬼使神差的却迈不动脚步。\n");
	return 1;
}

void reset(){
	object ob;
	::reset();
	if(ob = present("lu's corpse", this_object())){
		destruct(ob);
	}
	if(ob = present("yang's corpse", this_object())){
		destruct(ob);
	}
}
