#include <ansi.h>
inherit QUESTNPC;
inherit F_MASTER;
//inherit SSERVER;

void create()
{
	set_name("杜桐轩", ({ "du tongxuan", "du" }) );
	set("gender", "男性" );
	set("nickname",BLU"翰林学士"NOR);
        set("title","权倾京城     南霸");
        set("quality","evil");
	set("age", 47);
	set("int", 25);
	set("per", 20);
	set("str", 40);
	set("dur", 35);
	set("cor", 35);
	set("fle",20);
	set("long",
"这人很高，很瘦，穿著极考究，态度极斯文，年纪虽不甚大，两翼却已斑
白，一张清瘤瘦削的脸上，仿佛带著三分病容，却又带著七分威严，令人
绝不敢对他有丝毫轻视。\n");
        set("force_factor", 35);
	set("max_force",2000);
	set("force",2000);
        set("combat_exp", 3300000);
        set("score", 12000);
        set_skill("unarmed", 180);
        set_skill("force", 80);
        set_skill("parry", 160);
        set_skill("literate", 130);
	set_skill("dodge", 150);
	set_skill("puti-steps",150);
	set_skill("changquan", 290);
	map_skill("unarmed", "changquan");
	map_skill("dodge","puti-steps");
	set("class","official");
 
	setup();
	carry_object(__DIR__"obj/bluecloth")->wear();
	carry_object(__DIR__"obj/baiyubi");
	carry_object(__DIR__"obj/yubanzhi");
	add_money("gold",5);
}

int normal_busy(object opp)
{
	if(random(opp->query("combat_exp"))>1500000)
		return 0;
	if(opp->query_temp("weapon"))
		message_vision(HIB"杜桐轩双臂暗施内劲，竟将$N的兵器粘于手上！！\n"NOR,opp);
	else
		message_vision(HIB"杜桐轩双臂暗施内劲，竟将$N的出招粘于手上！！\n"NOR,opp);
	opp->start_busy(3);
	return 1;
}

int normal_att(object opp)
{
	if(random(100)>70)
	command("perform yuhuan "+opp->get_id());
	return 1;
}

int alert_busy(object opp)
{
	if(random(opp->query("combat_exp"))>2500000)
		return 0;
	if(opp->query_temp("weapon"))
		message_vision(HIB"杜桐轩双臂暗施内劲，竟将$N的兵器粘于手上！！\n"NOR,opp);
	else
		message_vision(HIB"杜桐轩双臂暗施内劲，竟将$N的出招粘于手上！！\n"NOR,opp);
	opp->start_busy(3);
	return 1;
}

int alert_att(object opp)
{
	if(random(100)>50)
	command("perform yuhuan "+opp->get_id());
	return 1;
}

int flee_busy(object opp)
{
	if(random(opp->query("combat_exp"))>4000000)
		return 0;
	if(opp->query_temp("weapon"))
		message_vision(HIB"杜桐轩双臂暗施内劲，竟将$N的兵器粘于手上！！\n"NOR,opp);
	else
		message_vision(HIB"杜桐轩双臂暗施内劲，竟将$N的出招粘于手上！！\n"NOR,opp);
	opp->start_busy(3);
	return 1;
}

int flee_att(object opp)
{
	if(random(100)>10)
	command("perform yuhuan "+opp->get_id());
	return 1;
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


*/
