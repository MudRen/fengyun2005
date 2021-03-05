//  特点：每６０秒钟会有１５秒的超级护卫

#include <ansi.h>
inherit NPC;
void smart_fight();
#include <combat.h>

void create()
{
	object weapon;
        set_name("百朝臣", ({ "bai chaocheng","bai","chaocheng" }) );
        set("title",WHT"号令传天下"NOR);
		set("nickname",MAG"众生齐聚我身旁"NOR);
        set("gender", "男性" );
		set("class","swordsman");

		set("age",33);
//		set("per",37);

		set("no_busy",2);

        set("combat_exp", 10000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );
//		set_temp("apply/haste",200);
        set_skill("zen", 300);
        set_skill("buddhism", 300);
        set_skill("lamaism", 300);
        set_skill("xiaodao", 800);

        set_skill("unarmed", 250);
        set_skill("fumostaff", 220);
        set_skill("demosword", 220);
        set_skill("staff", 220);
        set_skill("yizhichan", 220);
        set_skill("dabei-strike", 350);
        set_skill("luoriquan", 350);
        set_skill("iron-cloth", 220);
        set_skill("xisui", 220);
        set_skill("magic", 220);
        set_skill("force", 220);
        set_skill("snowforce", 220);
        set_skill("music", 220);
        set_skill("blade", 220);
        set_skill("sword", 220);
        set_skill("strategy", 300);
        set_skill("leadership", 300);
        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("summonwolf", 220);
        set_skill("chillblade", 220);
        set_skill("qiuzhi-sword", 180);
        set_skill("tie-steps", 220);
        set_skill("stormdance", 200);
        set_skill("lingxi-zhi", 200);
        set_skill("calligraphy",360);
        set_skill("shuaijiao",240);
        set_skill("sheolmagic",240);
        set_skill("necromancy",240);
        set_skill("shadowsteps",360);
        set_skill("celecurse",220);
        set_skill("liuquan-steps",300);


        map_skill("iron-cloth", "xisui");
        map_skill("unarmed", "shuaijiao");
        map_skill("blade", "chillblade");
        map_skill("magic", "music");
        map_skill("spells", "necromancy");
        map_skill("staff", "fumostaff");
        map_skill("force", "snowforce");
        map_skill("sword", "demosword");
        map_skill("parry", "qiuzhi-sword");
        map_skill("dodge", "liuquan-steps");

		setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("黄绸大袍", ({ "cloth" }) );
		weapon->set("long","");
		weapon->set("value",0);
		weapon->wear();

		weapon=carry_object("/obj/music/qixianqin");
		weapon->set_name("烽火传烟令", ({"linbai" }) );
		weapon->set("long","");
		weapon->set("value",0);


}




void dist(object ghost)
{
	if (!ghost)
		return;
	set_temp("timer/solidghost",0);
	message_vision(BLU"$N在空中打了个旋儿，形体渐渐消散无影．．．\n"NOR,ghost);
	destruct(ghost);
	return;
}

void smart_fight()
{
//	object *inv;
//	int i;
//	object me = this_object();
//	object ghost,ob,*enemy;
	set("atman",2000);

/*
	set("class","official");
	ccommand("perform npc_alert");
	ccommand("perform npc_alert");

	set("class","wolfmount");
	ccommand("perform npc_xiao");
	ccommand("perform npc_xiao");
	ccommand("perform npc_xiao");
	ccommand("perform npc_xiao");

	if (random(2))
	{
	set("class","taoist");
	ccommand("cast npc_invocation");
	ccommand("cast npc_invocation");
	}
	else
	{
	set("class","baiyun");
	ccommand("wield all");
	ccommand("conjure guanglingsan");
	ccommand("unwield all");
	}
	
	if (!query_temp("timer/solidghost") && time()>query("annie/sh")+30)
	{
		set_temp("timer/solidghost",1);
		message_vision(HIB"\n一个亡灵突然自远方飘了过来，对$N发出了令人毛骨悚然的笑声：“主人，有什么吩咐．．．”\n"NOR,this_object());
		ghost=new("/obj/npc/solidghost");
		ghost->invocation(me,200);
		ghost->set("name","无名亡灵");
		ghost->move(environment());
		set("annie/sh",time());
		ob=ghost;
		enemy=query_enemy();
		i = sizeof(enemy);
		while(i--) {
			if( enemy[i] && living(enemy[i]) ) {
				ob->kill_ob(enemy[i]);
				enemy[i]->kill_ob(ob);
			}
		}
//		ob->set("possessed",this_object());
		call_out("dist",180,ob);
	}	*/


	if (query("ac")+ 60 < time() && !is_busy())
	{
		set("ac",time());
		ccommand("perform npc_summon5");

/*			stop_busy();
	ccommand("perform npc_summon3");
			stop_busy();
	ccommand("perform npc_summon2");
			stop_busy();
	ccommand("perform npc_summon1");	*/
	}

	return;
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/

