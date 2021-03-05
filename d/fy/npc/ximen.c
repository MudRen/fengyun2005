inherit NPC;
#include <ansi.h>
int kill_him();
int fanghe();
int peiyu();
void smart_fight();

void create()
{
        object armor;
        set_name("西门风", ({ "ximen feng" }) );
        set("gender", "男性");
        set("age", 65);
        set("long","这位号称软功天下第一的武林名人在冷冷瞧着你，眼神中
带着惊讶，也带着怜悯。。\n" );
        set("inquiry", ([
            	"俞独鹤" : (: kill_him :),
             	"俞放鹤" : (: fanghe :),
              	"俞佩玉" : (: peiyu :),
   	]));
      
      	set("chat_chance", 1);
	set("chat_msg", ({
	 	"西门风笑道：“先天无极门的威名，岂是你这小辈可以想象的！”\n",
	 	"西门风道：好茶呀好茶！\n",
	}) );
	  
        set("attitude", "friendly");
        set("title",HIY"茅山"NOR);
        set("nickname",HIY"西门无骨"NOR);
        set("score", 10000);
        set("reward_npc", 1);
	set("difficulty",5);
	set("class","lama");
        set("no_busy",6);
        
        set("toughness",150);
        
        set("combat_exp", 2500000);        
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );

	set_skill("perception", 150);          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 180);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic",150);
        set_skill("bloodystrike", 200);
	set_skill("iron-cloth",1000);
	set_skill("kwan-yin-spells",130);
	        
        map_skill("unarmed","bloodystrike");
        map_skill("iron-cloth","xisui");
	map_skill("spells","kwan-yin-spells");        
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup();

//        add_money("gold", random(5));
        armor=new("/obj/armor/cloth");
	armor->set_name(HIW"软玉袍"NOR,({"cloth"}) );
	armor->move(this_object());
	armor->wear();
}

 
int kill_him()
{
        object me;
        me = this_player();
        command("say 看来你知道得真不少！！ \n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        return 1;
}

int fanghe()
{
    	command( "say 放鹤兄是我先天无极门的掌门人。");	
    	return 1;
}


int peiyu()
{
    	command ("say 这小子是我义兄不成材的儿子。");
    	return 1;
}

smart_fight()
{
	int i/*,num*/;
	object *enemy, who;
	who = this_object();
	if (who->is_busy()) return;
	enemy = this_object()->query_enemy();
	for(i=0;i<sizeof(enemy);i++)
	{
		if (enemy[i]->is_zombie() && random(2))
		{
			who->cast_spell("ni");
			return;
		}		
	}
	return;
}