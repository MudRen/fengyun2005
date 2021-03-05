#include <ansi.h>
inherit NPC;

void create()
{
    set_name("西门玉", ({"ximen yu","ximen"}) );
        set("gender", "男性" );
        set("nickname", HIC"七月十五"NOR);
        set("title", "青龙会 分舵舵主");
        set("long", "
一张很斯文，很和气，白白净净的脸，胡子修饰得干净而整齐。背负着
双手，施施然地踱着方步，不但脸带着微笑，眼睛也是笑眯眯地。他看
来就像是个特地来拜访朋友的秀才。\n");
 	set("attitude", "friendly");
 	set("class","beggar");
 	set("age", 45);
  	
    	set("reward_npc", 1);
        set("difficulty", 5);
    	
    	set("combat_exp", 4000000);

       	set_skill("unarmed", 200);
        set_skill("dragonstrike",180);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("move", 150);
        set_skill("five-steps",180);
        
        map_skill("dodge","five-steps");
        map_skill("unarmed","dragonstrike");
        map_skill("move","five-steps");
       
        set("no_busy",4);

        set("chat_chance", 1);
        set("chat_msg", ({
        "西门玉看着躺在血泊中的高立和双双，冷笑道：谁背叛青龙会，这就是下场。嘿嘿。\n",
		"西门玉冷笑吟道：七月中元日，地官降下，定人间善恶，道士于是日诵\n经，饿鬼囚徒，亦得解脱。\n",
        }) );

        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/stone_5");

}

void killed(object me){
	message_vision("$N不可置信般望着穿喉而过的银枪，喃喃道：怎么可能。。怎么可能，高立你 
明明。。已没有一点。。信心和勇气了。。。不会有。。\n", this_object()); 
	call_out("dead", 3, me);
	return;
}

void dead(object me){
	object gao;
	if(present("gao li", environment()) && present("shuang shuang", environment())){
		gao = present("gao li", environment());
		this_object()->set_temp("last_damage_from",gao);	
		gao->do_leave(me);
	}
	this_object()->die();
}

void die(){
	object *inv, ob, killer;
	int i;
	if(objectp(killer=query_temp("last_damage_from") ))
	if (killer->query("combat_exp")<4000000) {
		::die();
		return;
		}
	inv = all_inventory(this_object());
	for(i=0;i<sizeof(inv);i++){
		ob = inv[i];
		if(ob->query("name")== HIM"紫水晶"NOR) {
			destruct(ob);
		}
	}
	::die();
}