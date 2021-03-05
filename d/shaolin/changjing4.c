#include <ansi.h>
inherit ROOM;
void create()
{
	object ob1,ob2,con;
        set("short", "藏经阁");
        set("long", @LONG
藏经楼顶，这里的每件物品都是稀世之宝，底下三层还只是略加护卫，而这里
非少林弟子，绝难进入，一部华严血经，乃道公禅师历时二十八年以鲜血写成，更
有几束梵文贝叶经，是以刀刻贝叶而成，千年不变，可惜不识梵文，难解其意。
LONG
        );
        set("exits", ([ 
  		"down" : __DIR__"changjing3",
	]));
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",30);
	set("no_fly",1);
	set("no_lu_letter",1);
	
	set("item_desc", ([
	"窗口":"藏经阁顶楼的一扇小窗，只要稍缩身形就可以跃(jumpout)进跃出。\n",
	"window":"藏经阁顶楼的一扇小窗，只要稍缩身形就可以跃(jumpout)进跃出。\n",
	]) );
	

	setup();
	con = new(__DIR__"obj/he");
	ob1 = new(BOOKS"chant_75");
	ob2 = new(BOOKS"skill/yoga_0");
	if(con && ob1 && ob2)
	{
		ob1->move(con); 
		ob2->move(con); 
		con->move(this_object());
	}
}


void init()
{
	add_action("do_get","get");
	add_action("do_jumpout","jumpout");
	if(userp(this_player()))
		call_out("stealing",5+random(10),this_player());
}

int do_jumpout(string arg)
{
	object me;
	int i;
	object room;
   	me = this_player();
	i = me->query_skill("move",1);

	message_vision("$N足下一点，身形一掠而起，自窗口电射而出！\n",me);
	room = find_object(__DIR__"changjing");
	if (!objectp(room)) room = load_object(__DIR__"changjing");
	if (REWARD_D->riddle_check(me,"多事之秋") != 3 || REWARD_D->riddle_check(me,"守经楼") != 2)
	{
		tell_object(me,HIR"\n你突然发现窗外什么也没有，一口真气散去，整个人直直地向地面坠下！！\n"NOR);
		tell_object(me,HIW"．．．啊啊啊啊啊啊啊！！！\n"NOR);

		me->add_temp("block_msg/all",1);
		me->move(room);
		message_vision(HIY"\n你眼前一花，一个人影从藏经楼上飞坠而下，"NOR,me);

		if (i < 50)
		{
			message_vision(HIR"摔了个脑袋开花！\n"NOR,me);
			me->add_temp("block_msg/all",-1);
			me->set_temp("last_damage_from","想不开从藏经阁上跳楼自尽了。");
			// 嗯，通告一下....
			me->die();
			return 1;
		}
		else
		{
			message_vision(HIW"摔了个七荤八素，昏倒在你眼前。\n"NOR,me);
			me->add_temp("block_msg/all",-1);
			me->unconcious();
			return 1;
		}
	}
	if (i<80)
	{
		tell_object(me,HIR"\n你的真气突然涣散，心中一震，不禁后悔为什么当初没有好好修习轻功．．．\n可是现在说什么都已经晚了，你整个人直直地向地面坠下！！\n"NOR);
		tell_object(me,HIW"．．．啊啊啊啊啊啊啊！！！\n"NOR);
		i=random(i);

		me->add_temp("block_msg/all",1);
		me->move(room);
		message_vision(HIY"\n你眼前一花，一个人影从藏经楼上飞坠而下，"NOR,me);
		if (i < 30)
		{
			message_vision(HIR"摔了个脑袋开花！\n"NOR,me);
			me->add_temp("block_msg/all",-1);
			me->set_temp("last_damage_from","想不开从藏经阁上跳楼自尽了。");
			// 嗯，通告一下....
			me->die();
			return 1;
		}
		else
		{
			message_vision(HIW"摔了个七荤八素，昏倒在你眼前。\n"NOR,me);
			me->add_temp("block_msg/all",-1);
			me->unconcious();
			return 1;
		}
	}
	tell_object(me,HIG"\n你提起真气，在空中一个鹞子倒翻身，干净利落地窜上了藏经阁顶。\n\n"NOR);

	room = find_object(__DIR__"changjing5");
	if (!objectp(room)) room = load_object(__DIR__"changjing5");
	me->move(room);
	REWARD_D->riddle_set(me,"守经楼",3);
	return 1;
}

int do_get(string arg)
{
	string what;
	object me;
	me = this_player();
	if(!userp(me)) return 0;
	if(!arg) return 0;
	if(sscanf(arg,"%s",what) !=1) return 0;
	if(what== "all" || what  == "jingshuhe" || what == "jingshuhe 1" || what == "jingshuhe 0")
	{
		message_vision("$N看了看，四下无人，真想把经书揣入怀中，可是一想到
会被少林追杀，心就虚了下来．．．\n",me);
		return 1;
	}
}

int stealing(object me)
{
	object ob;
	if(environment(me) == this_object() && !present("mysterious figure",this_object()))
	{
		if (REWARD_D->riddle_check(me,"多事之秋") == 3 && REWARD_D->riddle_check(me,"守经楼") == 1)
		{
			ob = new(__DIR__"npc/master_17_7");
			if (me->query("combat_exp")> ob->query("combat_exp"))
				ob->set("combat_exp", me->query("combat_exp"));
			"/feature/nada"->reset_npc(ob);
			ob->full_me();
			message_vision("一阵微风从窗外吹过，$N的眼睛不禁眨了一下。。。\n",me);
			if(ob)
				ob->move(this_object());
//			REWARD_D->riddle_set(me,"守经楼",2);
	// 暂时不算失败
		}
	}
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


