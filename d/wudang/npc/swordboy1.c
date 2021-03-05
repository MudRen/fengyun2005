inherit NPC;
#include <ansi.h>
void smart_fight();
void smart_attack();

void create()
{
        set_name(HIY"金剑"NOR, ({ "gold boy" }) );
        set("gender", "男性");
        set("age", 15);
        create_family("武当派", 58, "剑童");

        set("long",
"一个活泼伶俐的小童，乃掌门石雁的爱徒之一。\n"
);
	  
        set("attitude", "friendly");
	set("class","wudang");
        
        set("combat_exp", 1200000);        
       
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );       

        set_skill("perception",200);  
        set_skill("move", 120);
        set_skill("force", 120);
        set_skill("unarmed", 180);
        set_skill("sword", 130);
        set_skill("parry", 130);
        set_skill("dodge", 130);
        set_skill("spells",100);
        set_skill("qixing",100);                        
        set_skill("taijiforce", 130);
	set_skill("five-steps",120);
	set_skill("taiji",140);
	set_skill("three-sword",135);
        
        map_skill("spells","qixing");
        map_skill("unarmed","taiji");
        map_skill("force", "taijiforce");
        map_skill("dodge","five-steps");
        map_skill("move","five-steps");
        map_skill("parry","three-sword");
        map_skill("sword","three-sword");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup();

        carry_object(__DIR__"obj/goldsword")->wield();
	carry_object("/obj/armor/cloth")->wear();
}

 
void init()
{
//      object ob;
        ::init();
	add_action("do_killing","kill");
}

int do_killing(string arg)
{
    object player, victim;
    string id;
//  int sen;

    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        id= victim->query("id");
        if( id == "silver boy" || id == "iron boy" || id == "bronze boy")
        {
            message_vision("$N"+CYN"喝道：上步高探马！\n"NOR, this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            return 0;
        }
    }
    return 0;
}


smart_fight()
{
	int i;
	object *enemy, who;
	who = this_object();
	enemy = this_object()->query_enemy();
	i = sizeof(enemy);
/*	if (i>1 && enemy[1]->is_zombie()) {
		who->cast_spell("zombie-bolt");
		return;
	}*/
	who->smart_attack();
	return;
}

smart_attack() {
	this_object()->perform_action("sword.nianzijue");	
	return;
	}