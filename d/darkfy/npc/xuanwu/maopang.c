//Tushen@Fygroup
//Based on Silencer's code.Copyrights all reserved.
inherit SMART_NPC;
#include <ansi.h>
void female_mingyue();
void create()
{
        set_name("猫胖", ({ "mao pang" }) );
        set("gender", "女性");
        set("age", 23);     
      	set("chat_chance", 1);
	set("chat_msg", ({
"猫胖恶狠狠的扑了上去，挠了无言满脸花。\n",
"猫胖寂寥的蹲在地上，甩着毛茸茸的大尾巴。"
	}) );
        set("attitude", "friendly");
        set("title",BLK"玄武"NOR);
        set("nickname", HIG"唐三彩诗社 撑着降落伞的"NOR);
        set("score", 200000);
        set("reward_npc", 1);
		    set("difficulty",50);
		    set("class","moon");
        set("combat_exp", 16000000);        
        set("annie/chillblade_qinghui", 3);
    set("perform_busy_d", "moon/dodge/stormdance/hanlinluoxue");
    set("perform_busy_d", "moon/dodge/stormdance/shuangtianxuewu");
		set("perform_weapon_attack", "moon/throwing/starrain/fengloufeiyan");
	  set("perform_weapon_attack1", "moon/throwing/starrain/tianheyixian");
	  set("perform_weapon_attack2", "moon/blade/chillblade/qinghui");
    set("perform_buff_1", "moon/force/snowforce/bingpojingbi");
    set("perform_buff_2", "moon/force/snowforce/shuanghuaningjie");
    set("perform_buff_3", "moon/force/snowforce/wufangbianhuan");
		set("perform_buff_4", "berserker/force/gaunforce/damageup");
		set("perform_buff_5", "berserker/force/gaunforce/powerup");
		  
		  set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
          
        set_skill("move", 270);
        set_skill("perception", 300);
        set_skill("force", 270);
        set_skill("spells", 300);
        set_skill("unarmed", 280);
        set_skill("parry", 300);
        set_skill("dodge", 280);
        set_skill("magic", 300); 
        set_skill("blade", 300);
        set_skill("throwing", 300);
        
        set_skill("snowforce", 180);
		    set_skill("fengyu-piaoxiang", 200);
        set_skill("chillblade", 230);
        set_skill("starrain",300);
        set_skill("stormdance" , 180);
        set_skill("heart-listening", 200);
        
        map_skill("blade","chillblade");
        map_skill("force", "snowforce");
        map_skill("dodge","stormdance");
        map_skill("move","stormdance");
        map_skill("parry","chillblade");
        map_skill("spells","heart-listening");
        setup();

    	carry_object("/obj/weapon/blade",([	
    						"name":  "毛茸茸的大尾巴",
    						"long": "一条长长的，毛茸茸的大尾巴。\n",
    						 ]))->wield();  
    	carry_object("/obj/weapon/throwing",([	
    						"name":  "长长的胡子",
    						 ]))->wield();  
    	carry_object("/obj/armor/cloth",([	
    						"name":  "油光发亮的皮毛",
    						 ]))->wear();  
}


