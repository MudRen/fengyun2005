inherit NPC;
#include <ansi.h>
int silencer();


void create()
{
        set_name(HIW"无名客"NOR, ({ "ke" }) );
        set("title",YEL"探花楼"NOR);
        set("gender", "男性" );
        
        set("age", 32);
        set("str", 50);
 	set("dur",10);
        set("cor", 14);
        set("per", 4);
        set("cps", 29);
        set("int", 25);
        set("no_fly",1);
        set("long", "无名客，探花楼顶楼主持，你若给他10两银子，可以训练打斗。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
        }) );	
        set("inquiry", ([
            "silencer" : (: silencer :),
        ]));
        set("combat_exp", 10000000);
        set("attitude", "friendly");
        set("max_force", 500);
        set("force", 500);
        set("force_factor", 10);
        set_skill("yoga",151);
        set_skill("dodge",50);
        set_skill("move",50);
        set_skill("unarmed",50);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object who, object ob)
{
	object another;
	object *inv;
	int i,j;
	
	if (who->query("combat_exp")<=3000000) {
		ccommand("say 你还是多练几年吧。");
		return 0;
	}	
	
	inv=all_inventory(environment(this_object()));
	for (i=0;i<sizeof(inv);i++) {
		if (inv[i]->query("dungeon_npc")) j++;
	}
	
	if (j>2) {
		ccommand("say 先处理掉在场的再说吧!");
		return 0;
	}
	
	if( ob->value() >= 1000) {
        	message_vision("$N拿起法杖挥了一下。\n",this_object());
	        another = new("/d/eren2/temp/fighter1");
		another->move(environment(this_object()));
	        another->auto_npc_setup("fighter",300,200,1,"/obj/weapon/","random","random");
		another->set("name",another->query("myname"));
                message("vision",another->query("name")+HIG"突然出现在面前说:“报到！杀谁？“\n"NOR,environment(this_object()));              
                        return 1;
                } else {
                    	command("say 这点，怕是不够。。。\n");
                        return 0;
                }
        return 0;
} 

void die(){
	 message_vision("$N微微一凝气，脸色又恢复了红润。\n", this_object());
	full_me();
}

void init() {
}



int silencer(){
	object me, another;
	string npc_name;
	
	me=this_player();
	
	if (!wizardp(me)) {
		message_vision("$N说：小孩子不要乱问。\n",this_object());
		return 1;
	}
	
	if (!npc_name=this_object()->query("npc_name"))
		npc_name="random";
	
	message_vision("$N一躬到底说，“敢不从命！“\n",this_object());
       	message_vision("$N拿起法杖轻轻挥了一下。\n",this_object());
        another = new("/d/eren2/temp/fighter1");
	another->move(environment(this_object()));
        another->auto_npc_setup("fighter",300,200,1,"/obj/weapon/","random",npc_name);
	another->set("name",another->query("myname"));
	if (this_object()->query("npc_exp"))
		another->set("combat_exp",this_object()->query("npc_exp"));
	message("vision",another->query("name")+CYN"说到:“江湖子弟江湖志。江湖人年轻的时候，总是想，跟当世的一
些大人物较量，纵比输了也好，总要把金刀往宝剑上碰出星花，才知道是不是
好刀……在下燕云三十六骑之"+another->query("name")+CYN"，只求大师赐教，一偿夙愿。“\n"NOR,environment(this_object()));              	
	return 1;
}

