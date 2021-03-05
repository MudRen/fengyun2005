inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIG"无言"+MAG"怪物"+HIG"制造中心"NOR, ({ "alien queen","queen" }) );
        set("gender", "女性" );
        
        set("age", 32);
        set("str", 25);
 	set("dur",100);
        set("cor", 14);
        set("per", 4);
        set("cps", 29);
        set("int", 25);
        set("long", "无言怪物制造中心，生产各类疑难怪物。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                "怪物制造中心说：给我一两金子，送你一个娃子。\n",               
                }) );	
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("max_force", 500);
        set("force", 500);
        set("force_factor", 10);
        set_skill("yoga",151);
        set_skill("dodge",50);
        set_skill("move",50);
        set_skill("unarmed",50);
        set("skill_public",1);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object who, object ob)
{
	object another;
	object *inv;
	int i,j;
	
	if (who->query("combat_exp")<=2500000) {
		ccommand("say 你还是多练几年吧，我儿子一口能吃你俩。");
		return 0;
	}	
	
	inv=all_inventory(environment(this_object()));
	for (i=0;i<sizeof(inv);i++) {
		if (inv[i]->query("dungeon_npc")) j++;
	}
	
	if (j>3) {
		ccommand("say 先处理掉在场的再说吧!");
		return 0;
	}
	
	if( ob->value() >= 10000) {
        	message_vision("$N说，我就忍痛割爱一把吧。\n",this_object());
        	message_vision("$N哼哼了几声。\n",this_object());
        	another = new(__DIR__"fightnpc");
		another->move(environment(this_object()));
                message("vision",another->query("name")+"说:“报到！杀谁？“\n",environment(this_object()));              
                        return 1;
                } else {
                    	command("say 养孩子不容易啊。。。\n");
                        return 0;
                }
        return 0;
} 

void die(){
	 message_vision("$N微微一凝气，脸色又恢复了红润。\n", this_object());
     this_object()->full_me();
//	"/cmds/imm/full"->main(this_object(),"");
}