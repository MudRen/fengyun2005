// XXDER@FY3
inherit SMART_NPC;
#include <ansi.h>
void create()
{
    set_name("剑狂" , ({ "jian kuang","jian" }) );
    set("long", "因剑而狂，为剑而狂。\n");
	set("attitude", "friendly");
    set("age", 62);
        set("gender", "男性" );
        create_family("白云城",1, "剑客");
    set("per",4);
    set("combat_exp", 2000000);
	set("class","baiyun");
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
     }) ); 		

	auto_npc_setup("wang",150,150,1,"/obj/weapon/","fighter_w","feixian-sword",1);
	set_skill("iron-cloth",100);
	set_skill("xisui", 50);
	map_skill("iron-cloth","xisui");
	setup();
    carry_object("/obj/armor/cloth")->wear();
}

int accept_fight(object who)
{
	if (REWARD_D->riddle_check(who,"王图一梦") !=9 )
	{
		ccommand("shake");
		ccommand("say 师尊在前，剑狂不敢放肆。");
		return 0;
	}
	ccommand("emote 持剑向叶孤城微一点头，并无多言，手中冷光乍现，含光倏然刺向"+who->name(1)+"。");
	return 1;
}

void lose_enemy(object winner)
{
	object ye;
	ye = present("Master ye",environment());
	if (!ye || userp(ye))
		return;
	
	if (REWARD_D->riddle_check(winner,"王图一梦") !=9 )
		return;
		
	ye->ccommand("emote 不动声色，道：好。");
	ye->ccommand("emote 轻轻扭动了一下白玉龙椅上的龙头。 ");
	message_vision(YEL"\n“喀吱吱”一阵绞盘声响龙椅后的白玉壁突然一转，现出一扇石门。\n\n"NOR,ye);
	ye->ccommand("emote 肃然道：白云城正当成就霸业之时，你修行尚可，当能入室。
真正的白云城主在后面的白云观中，你可前去叩见。");
	ye->ccommand("kick "+winner->query("id"));
	message_vision(YEL"\n$N被踢得一头扎进了石门之中。\n"NOR,winner);
	winner->move(load_object("/d/baiyun/changlang"));
	winner->perform_busy(1);
	message("vision",winner->name()+"七横八竖的飞了进来，重重的跌在地上。\n",environment(winner),winner);
	REWARD_D->riddle_set(winner,"王图一梦",10);
	return ;
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
