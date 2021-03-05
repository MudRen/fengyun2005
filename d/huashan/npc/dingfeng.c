#include <ansi.h>
inherit NPC;

void create()
{
    	set_name("丁枫", ({ "ding feng", "ding", "feng" }));
    	set("long", "
这轻衫少年袍袖飘飘，不但神情很潇洒，人也长得很英俊，
脸上更永远都带着笑容。\n" );
 	set("nickname", HIC "玉树临风" NOR);
 	set("gender", "男性");
 	set("age", 27);
 	set("int", 24);
 	set("con", 25);
 	set("no_arrest",1);
	
	set("class","huashan");
 	set("combat_exp", 800000);
 	set("attitude", "friendly");

 	set("chat_chance", 1);
 	set("chat_msg", ({
"丁枫喃喃道：华山派这一套“清风十三式”的确是曼妙无铸，非人能及，
连昆仑的“飞龙大九式”都自愧不如。\n ",
"丁枫微笑道：“清风十三式”妙就妙在“清淡”两字,讲究的正是：似有似无，
似实似虚，似变未变 。\n",
 }) );
 	set("inquiry",([
  		"清风十三式" : "此书乃华山镇山之宝，可是却失传了，唉！\n",
 	]) );
	
	set_skill("unarmed", 150);
	set_skill("move", 100);
	set_skill("dodge", 150);
	set_skill("parry", 100);
	set_skill("force", 100);
	set_skill("sword", 100);
	set_skill("hanmei-force",100);
	set_skill("qingfeng-sword", 140);
	set_skill("anxiang-steps", 100);
	
	map_skill("force","hanmei-force");
        map_skill("move", "anxiang-steps");
	map_skill("parry", "qingfeng-sword");
	map_skill("sword", "qingfeng-sword");
        map_skill("dodge", "anxiang-steps");

	setup();
    	carry_object("/obj/armor/cloth")->wear();
    	carry_object("/obj/weapon/sword")->wield();

}

