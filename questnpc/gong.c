#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;
void do_fight();
void create()
{
	set_name("宫九", ({ "gong jiu", "gong" }) );
	set("gender", "男性" );
        set("nickname",HIC"天下无双"NOR);
        set("title","太平王府     世子");
        set("age", 27);
	set("quality","evil");
	set("int", 70);
	set("per", 38);
	set("str", 180);
	set("dur", 35);
	set("cor", 110);
	set("agi",100);
        set("long",
"他便是宫九，那个由毒蛇的液，狐狸的心，北海中的冰雪，天山上的岩石，狮子的勇猛，豺狼
的狠辣，骆驼的忍耐，人的聪明，再加上一条来自十八层地层下的鬼魂构成的宫九。\n"
		);
	set("hunting",1);
        set("force_factor", 10);
        set("max_force",4000);
	set("force",4000);
        set("combat_exp", 50000000);
        set("score", -3000);
        set_skill("unarmed", 270);
        set_skill("sword", 270);
        set_skill("force", 200);
        set_skill("parry", 270);
        set_skill("literate", 300);
	set_skill("dodge", 270);
//	set_skill("gong-skill",200);
//	set_skill("yinghua-steps",150);
//	map_skill("unarmed", "gong-skill");
//	map_skill("dodge","yinghua-steps");
	set("strategy","hero");
		set("chat_chance",10);
		set("chat_msg",({
			"宫九刀锋般的目光正盯在你脸上，傲然道“我就是宫九，独一无二的宫九。”\n",
		})	);
//		set("chat_chance_combat",100);
//		set("chat_msg_combat",({
//			(:do_fight:),
//		})	);
        
	setup();
	carry_object(__DIR__"obj/redcloth")->wear();
	add_money("tenthousand-cash",1);
}

int normal_att(object opp)
{
	set("force_factor",10);
}

int alert_att(object opp)
{	
	if(random(100)>90)
		message_vision(HIR"宫九愉快对$N的笑道：“看来阁下还有那么两下子，在下也不得不稍微加点劲了。\n"NOR,opp);
	set("force_factor",450);
}


int flee_att(object opp)
{	
	if(random(100)>90)
		message_vision(HIR"宫九皱着眉头对$N的说道：“非要逼我用全力不可吗？。\n"NOR,opp);
	set("force_factor",750);
	
}










/*
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

void crazy(int i,int exp);
void init()
{	
	add_action("do_show","show");
}

void begin_crazy();

void remove_crazied()
{
	set("crazied",0);
}

int do_show(string arg)
{	
	object whip;

	if(!arg) 
	{
		write("你想给别人看什么东西？\n");
		return 1;
	}
	if( !whip=present(arg,this_player()))
	{	
		write("你身上没有这样东西呀？\n");
		return 1;
	}
	if (whip->query("skill_type")!="whip"||query("crazied")||(string)(NATURE_D->outdoor_room_description()) != "    " +
"夜幕低垂，满天繁星，四周一片暗灰。
")
	{
		message_vision("$N拿出手中的"+whip->name()+"给$n看，但$n什么反应都没有。。。\n",this_player(),this_object());
		return 1;
	}
	message_vision("$N拿出手中"+whip->name()+"在$n眼前晃了晃\n",this_player(),this_object());
	begin_crazy();
	set("crazied",1);
	call_out("remove_crazied",900);
	return 1;
}

void begin_crazy()
{
	object weapon;
	object me,ob;
	int exp;

	ob=this_object();
	me=this_player();
	
//	weapon=me->query_temp("weapon");
//	if(!this_object()->query_temp("crazy") )
//	if (weapon->query("skill_type")=="whip")

	{
		message_vision("宫九脸色忽然大变，两眼逐渐变红，倒在地上撕叫翻滚起来。\n",this_object());
		exp=this_object()->query("combat_exp");
		this_object()->start_busy(100);
		this_object()->set("combat_exp",1);
		call_out("crazy",4+random(1),0,exp);
		return;
	}
}


void crazy(int i,int exp)
{	
	object ob,me,weapon;
	
	ob=this_object();
	me=this_player();
	weapon=me->query_temp("weapon");

	if(ob)
	if (!weapon||weapon->query("skill_type")!="whip"||i>12)
	{
		message_vision("$N忽又恢复了冷静，冷冷的望着$n道：“凡是和我作对的，都只有死路一条。”\n",ob,this_player());
		ob->stop_busy();
		ob->set("combat_exp",exp);
//		ob->set("kee",ob->query("max_kee"));
		ob->delete_temp("crazy");
		return;
	}
	else
	{	
		if(!random(2))
			message_vision("宫九的气息喘动如一头奔跑了数十里的蛮牛，已经疯狂般撕扯自己的衣服，喘着气，狂叫道：“打我，打我。”\n",ob);
		ob->receive_damage("kee",100);
		call_out("crazy",1+random(1),i+1,exp);
	}
}
*/