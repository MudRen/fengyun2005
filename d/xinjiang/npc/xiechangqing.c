inherit SMART_NPC;
#include <ansi.h>
int kill_him();

void create()
{
        set_name("谢长卿", ({ "xie changqing" }) );
        set("gender", "男性");
        set("age", 25);
        set("long",
"一个年轻而英俊的少年，他甚至在颤抖着，英俊的面庞上，也蒙着
一层死灰之色。。\n"
);
      
      	set("chat_chance", 1);
	set("chat_msg", ({
"谢长卿喃喃道：“我还年轻，我不能就这样无声无息地死去，而且那时
谷中再无他人，即使我作了昧心之事，又有谁会传将出去，唉！我想
人人都该为自己打算吧。”\n",
	}) );

        set("inquiry", ([
            "梅山民" : (: kill_him :),
            "mei shanmin" : (: kill_him :),
             ]));
		set("fly_target",1); 
        set("attitude", "friendly");
        set("title",HIG"点苍"NOR);
        set("nickname", HIG"落英剑"NOR);
        set("score", 0);
        set("reward_npc", 1);
		set("difficulty",2);
		set("class","legend");
       
        set("combat_exp", 3800000);        
        
//      set("perform_busy_d", "legend/dodge/fall-steps/luoyeqiufeng");
		set("perform_busy_u", "legend/unarmed/meihua-shou/meihai");
		set("perform_weapon_attack", "legend/sword/diesword/caidiekuangwu");
		set("perform_buff_1", "legend/force/qidaoforce/juqi");
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
        }) );
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 150);
        set_skill("sword", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
        set_skill("qidaoforce", 150);
		set_skill("fall-steps",200);
		set_skill("meihua-shou",200);
        set_skill("diesword",200);
        
        map_skill("unarmed","meihua-shou");
        map_skill("force", "qidaoforce");
        map_skill("dodge","fall-steps");
        map_skill("move","fall-steps");
        map_skill("parry","diesword");
        map_skill("sword","diesword");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup();

        carry_object("/obj/weapon/sword")->wield();
		carry_object("/obj/armor/cloth")->wear();
}

int kill_him()
{
        object me;
        me = this_player();
        if (this_object()->is_fighting()) return 1;
        message_vision(CYN"谢长卿怔了半晌说:此是我平生最憾之事....\n"NOR,this_object());
        message_vision(CYN"谢长卿突然扬起手中长剑，凝视片刻，陡然挥剑“擦”的一声，声响未歇，
剑交左手，又是“擦”的一声。只见他双手鲜血淋漓，两只大姆指跌落地上，他
用中食两指夹着长剑奋力一掷，“落英剑”化作一圈流光直飞而出，“扑”的一
声钉在树干上，剑柄带着小半截剑身左有摇震晃荡，接着头也不回的去了。\n"NOR,this_object());
        me->set("marks/谢长卿",1);
        destruct(this_object());
        return 1;
}