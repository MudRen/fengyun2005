inherit NPC;
inherit F_MASTER;
#include <ansi.h>


void smart_fight();
void smart_busy();
void smart_attack();


void create()
{
       	set_name("云松", ({ "master yunsong", "master","yunsong" }) );
       	set("nickname", RED"红衣喇嘛"NOR);
	set("gender", "男性" );
        set("long","
云松乃是葛伦高僧的关门小弟子，修行甚勤。葛伦以之为门下众弟子榜样。\n");

        set("age", 32);
		set("class","lama");
	
        create_family("大昭寺", 21, YEL"活佛"NOR);
    	set("rank_nogen",1);
    	    	set("ranks",({"藏僧","罗汉","金刚","高僧","尊者","大士","大师",
    		"上师","神僧","圣僧","法王","圣法王",YEL"大宝法王"NOR,
    		YEL"大德活佛"NOR,YEL"密宗传人"NOR,HIY"密宗宗主"NOR}));
		set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		
        set("reward_npc", 1);
		set("difficulty", 2);
        
        set("chat_chance", 1);
       	set("chat_msg", ({
                "云松叹了口气道：赤松大师兄，不知道现在怎么样了。。\n",
        }) );

		set("inquiry", ([
			"舍利子": "嗯....舍利子一定是我师妹胭松盗走的。\n",
			"胭松": "胭松在布达拉宫城的大招寺里。",
		]) );
	
	set("attitude", "peaceful");
	set("combat_exp", 3500000);
	
	set_skill("staff", 150);
    	set_skill("fengmo-staff", 150);
	set_skill("unarmed", 150);
	set_skill("bloodystrike", 150);
	set_skill("force", 150);
	set_skill("bolomiduo", 150);
	set_skill("spells",150);
	set_skill("parry",150);
	set_skill("kwan-yin-spells",150);
	set_skill("perception", 100);
	set_skill("literate", 100);
	set_skill("jin-gang",150);
	set_skill("iron-cloth", 150);
	set_skill("lamaism", 150);
	set_skill("foreknowledge", 100);
	set_skill("chanting", 150);
	
	map_skill("spells","kwan-yin-spells");
	map_skill("parry","fengmo-staff");
	map_skill("unarmed", "bloodystrike");
	map_skill("force", "bolomiduo");
    	map_skill("staff", "fengmo-staff");
    	map_skill("iron-cloth","jin-gang");
    	
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
        	(: smart_fight() :),
        }) );
        
		setup();
        carry_object(__DIR__"obj/redclothh")->wear();
        carry_object(__DIR__"obj/7staff")->wield();
}



void attempt_apprentice(object ob)
{
	    if(ob->query("marry") && !ob->query("jiebai")){
			message_vision("$N微微笑道，“施主红尘中人，不宜入我禅门。”\n", this_object(), ob);
			return;
    	}	
        command("smile");
        command("say 南無、阿唎耶，婆盧羯帝、爍缽囉耶、菩提薩埵。");
        command("recruit " + ob->query("id") );        
}



smart_fight()
{
	int i;
	object *enemy, who;
	who = this_object();
	if (who->is_busy()) return;
	enemy = this_object()->query_enemy();
	i = sizeof(enemy);
	if (i>2) {
		who->cast_spell("ni");
		return;
	}
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			if (enemy[i]->query_skill("iron-cloth")>300 
				|| enemy[i]->query("combat_exp")>who->query("combat_exp")) {
				who->cast_spell("an");
				switch( random(3) ) {
					case 0: command("grin");
						break;
					case 1: command("smile");
						break;
					case 2: command("smug");
						break;
					}
				return;
			}		
			this_object()->smart_attack();
			}
	}
	return;
}


smart_attack() {
	this_object()->ccommand("perform fuhu");	
	return;
}


void die()
{
    object killer, owner;
    if(objectp(killer = query_temp("last_damage_from")))
    {
    	if ( objectp(owner = killer->query("possessed")))
    		killer = owner;
    	REWARD_D->riddle_set( killer, "义助赤松",1);
    }    	
    ::die();
}
