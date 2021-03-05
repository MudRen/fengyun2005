
inherit QUESTNPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name(HIW"薛笑人"NOR, ({ "xue xiaoren", "xue" }) );
	set("nickname",HIG"天才白痴"NOR);
        set("title","杀人庄     二庄主");
	set("gender", "男性" );
        set("quality","evil");
        set("age", 53);
	set("int", 55);
	set("per", 30);
	set("long",
"他年纪最少也有四十多了，胡子已有些花白，身上却穿着件大红绣花的衣
服，绣的是刘海洒金钱，脚上还穿着双虎头红绒链，星光下看来，他脸色
似乎十分红润，仔细一看，原来竟涂着胭脂。\n"
		);
        set("max_force", 5000);
        set("force", 5000);
	set("force_factor", 50);
	set("cor",90);
	set("str",60);
        set("combat_exp", 5200000);
	set("bellicosity",0);
        set("score", -1500);
        set_skill("sword", 180);
        set_skill("force", 120);
        set_skill("parry", 120);
        set_skill("literate", 40);
	set_skill("dodge", 330);
        set("agi",25);
        set("int",30);
/*		set("chat_chance",10);
		set("chat_msg",({
"路小佳拈起一颗花生，剥开，抛起，然后看着这颗花生落到自己嘴里，闭上眼睛，
长长的叹了口气，开始慢慢咀嚼。\n",
"路小佳忽然笑笑 ，说道：“杀人是件干净痛快的事情。”他顿了一顿，又说道：
“所以在杀人之前，我一定要洗个澡。”\n",
		})	);
*/
 
	set_skill("sharen-sword", 120);
        map_skill("sword", "sharen-sword");
        map_skill("parry", "sharen-sword");
	set("flee_rate",60);
	set("alert_rate",80);
	set("strategy","conservative");
	set("w_type","sword");
	set("hunting",1);
	setup();
	carry_object(__DIR__"obj/xiuhuapao")->wear();
	carry_object(__DIR__"obj/hutoushoe")->wear();
        carry_object("/obj/weapon/sword")->wield();
}
/*
void init()
{
    object room;
    remove_call_out("hunting");
    if(!room=environment()) return 0;
	if(!room->query("no_fight"))
		hunting();
       call_out("hunting",1);
}

void hunting()
{
    object ob;
	//if (!interactive(ob = this_player())) return;
	ob = this_player();
    if( ob->is_character() && living(ob) && !userp(ob) && !ob->query("quality"))
	//CHANNEL_D->do_sys_channel("sys","I meet "+ob->name());
	{
		kill_ob(ob);
		ob->kill_ob(this_object());
	}
}
*/
int normal_att(object opp)
{
	if(random(100)<30)
	command("perform sharenruma");
}

int alert_att(object opp)
{
	if(random(100)<50)
	command("perform sharenruma");
}

int flee_att(object opp)
{
	if(random(100)<80)
	command("perform sharenruma");
}

int die_action()
{
	object killer;
	
	if(objectp(killer=this_object()->query_temp("last_damage_from")))
	if(present(killer,environment()))
	{
		message_vision(HIR"$N对$n狂叫道：“欺人太甚，老子跟你拼了！！！”\n",this_object(),killer);
		message_vision(HIR"$N不管不顾，发疯般得向$n扑了过去，$n促不及防，竟被攻了个手忙脚乱。\n",this_object(),killer);
		killer->die();
	}
	return 0;
}