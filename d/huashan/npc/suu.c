// ; annie 6.28.03
// dancing_faery@hotmail.com
// 那夜月华如水，有冷冷的青光在我手上闪烁。 
// 时隔二十一年，青葱甲重现江湖。  - annie 07.03.2003

// 八部众之阿修罗王 烟火散尽 苏小晓 
// EXP 8M KEE 24K GIN/SEN 16K RESIST/ALL 60
// STR 80 DMG 60 ATTACK 116K DODGE 100K PARRY 100K
// IMMUNE TO BUSY,20SEC IMMORTAL,STEAL
// 极高伤害·连击，春水罗衫·冰纨天障（改）

// A/D/P：远高于标准8M。此人可TK。

inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight(object who);

void create()
{
        object armor,weapon;
        set_name("苏小晓", ({ "suu xiaoxiao","suu"}) );
        set("gender", "女性" );
        set("title",YEL"大光明教 "NOR CYN"阿修罗王"NOR);
        set("nickname",WHT"烟火散尽"NOR);
        set("age", 20+random(10));
        set("attitude","friendly");

        set("long", "她薄薄的脂粉画得有些微残，眼睑和腮角染着浅浅的醉痕，眼
角是淡淡青晕，仿佛春睡初醒，醉意犹在，头发松松挽起，斜
插一只玳瑁梳子，懒懒的倚于松下，脸上微有愁色。\n"
                );
        set("class","demon");
    	set("combat_exp", 8000000); 
    	set("score", 10000);
        set("str",20);
        set("per",200);
        set("force",2500);
        set("max_force",2500);
        set("force_factor",130+random(100));
        set("atman",1500);
        set("max_atman",1500);
        set("mana",1500);
        set("max_mana",1500);
		
		set("real_suu",1);
        set("no_fly",1);
        set("no_arrest",1);
                
        set("resistance/gin",60);
        set("resistance/kee",60);
        set("resistance/sen",60);

        set("max_kee",24000);
        set("max_gin",16000);
        set("max_sen",16000);
        
        set_skill("heavendance",250);
        set_skill("blade",200);

        set_skill("demon-steps",200);
        set_skill("fall-steps",200);
        set_skill("anxiang-steps",200);
        set_skill("cloud-dance",200);
        set_skill("move",200);
        set_skill("dodge",200);

	    set_skill("perception",800);

        set_skill("meihua-shou",210);
        set_skill("unarmed", 300);
        set_skill("force", 200);

        set_skill("lingxi-zhi", 170);
        set_skill("spells",200);
        set_skill("parry",200);
        set_skill("kwan-yin-spells",200);
        set_skill("five-steps",180);
        set_skill("stormdance",400);
        set_skill("move",200);
        set_skill("dodge",200);

        set_skill("spring-water",200);
        set_skill("iron-cloth",200);
        map_skill("iron-cloth","spring-water");

        set("chat_chance", 1);
        set("chat_msg", ({
                "苏小晓扬起水袖遮在唇边，懒懒的打了一个呵欠。\n",
                "苏小晓叹道："YEL"华山派"NOR"，华山派……"YEL"枯梅"NOR"果然是个不中用的东西，这么点小事都办不好。\n",
                "苏小晓偏头看了你一眼，说道：既然来了，怎么还不动手？\n",
                "苏小晓垂下头去，望着手上一双泛着淡淡青光的雕花指甲。\n",
                }) );

    set("inquiry", ([
        "教主":   "action苏小晓打了一个呵欠，摇头道：若是要打听这等无聊事情，你大可不必来了。",
        "魔教":   "action苏小晓打了一个呵欠，摇头道：若是要打听这等无聊事情，你大可不必来了。",
        "大光明教":   "action苏小晓打了一个呵欠，摇头道：若是要打听这等无聊事情，你大可不必来了。",
        "西方神教":   "action苏小晓打了一个呵欠，摇头道：若是要打听这等无聊事情，你大可不必来了。",
        "青青":   "action苏小晓顾了你一眼，漫声道：青青么，就是你梦中情人，莫言我不知道。",
        "梦中情人":   "action苏小晓顾了你一眼，漫声道：你梦中情人么，就是青青，莫言我不知道。", // *snicker suu,*escape
        "华山":   "好好的"YEL"春水罗衫"CYN"，"YEL"冰纨天障"CYN"，传来传去竟传成那样，倒\n还要依着"YEL"暗青子"CYN"吃饭……这华山一派，不拜也罢。",
        "华山派":   "好好的"YEL"春水罗衫"CYN"，"YEL"冰纨天障"CYN"，传来传去竟传成那样，倒\n还要依着"YEL"暗青子"CYN"吃饭……这华山一派，不拜也罢。",
        "华真真":   "好好的"YEL"春水罗衫"CYN"，"YEL"冰纨天障"CYN"，传来传去竟传成那样，倒\n还要依着"YEL"暗青子"CYN"吃饭……这华真真嘛，不拜也罢。",
        "枯梅":   "枯梅么？有勇无谋，只给巾帼丢脸，算不得是个英雄。",
        "枯梅大师":   "枯梅么？有勇无谋，只给巾帼丢脸，算不得是个英雄。",
        "春水罗衫":   "春水罗衫在饮雨那里直是无敌，谁知道这代华山弟子竟\n练成那样，比我还更不如，真是不成气候。",
        "冰纨天障":   "春水罗衫在饮雨那里直是无敌，谁知道这代华山弟子竟\n练成那样，比我还更不如，真是不成气候。",
        "暗青子":   "不就是那乱丢垃圾，污人污眼的本事，叫什么"YEL"漫天花雨"CYN"\n，直如与人斗嘴斗得唾沫横飞的。",
        "漫天花雨":   "暗器用到漫天花雨这个份上，却也是登峰造极——臭极，烂极。",
         ]) );

        map_skill("spells","kwan-yin-spells");
        map_skill("unarmed", "lingxi-zhi");
        map_skill("force", "bolomiduo");
        map_skill("dodge","stormdance");
        map_skill("move","stormdance");
        map_skill("blade","heavendance");
        map_skill("parry","lingxi-zhi");
        
        set_skill("kaleidostrike",500);
        map_skill("unarmed", "kaleidostrike");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight(this_object()) :),
        }) );


        setup();

        carry_object(__DIR__"obj/longskirt")->wear();
        carry_object(__DIR__"obj/qingcong")->wield();

        carry_object(__DIR__"obj/paper2");

        set("reward_npc", 1);
        set("difficulty",20);

        set_temp("buff_type/blocked",1);        // 不動之界

}

int fight_ob(object who)
{
        if (query("immortal"))
                who->remove_enemy(this_object());
        ::fight_ob(who);
        return 1;
}

int kill_ob(object who)
{
        object me;
        int exp_r,busyst;
        if (query("immortal"))
                who->remove_killer(this_object());
        ::kill_ob(who);
        stop_busy();
        smart_fight(who);
        return 1;
}

void do_ck(object * tar)
{
        int i;
        set("immortal",0);
        delete("NO_KILL");
        set("resistance/kee",60);
        set("resistance/gin",60);
        set("resistance/sen",60);
        return;
}

void force_busy(int busy)
{
        message_vision(CYN"\n一圈淡青色的光芒在苏小晓身边浅浅晕开。\n"NOR, this_object());
        return;
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        message_vision(CYN"\n一圈淡青色的光芒在苏小晓身边浅浅晕开。\n"NOR, this_object());
        return;
}

void smart_fight(object who)
{
        object me,target,item;
        object * tar;
        int i;
        me = this_object();

        if (who != me)
            target = who;
        else
            target = select_opponent();

        if ((query("kee") < query("max_kee") / 2 || query("gin") < query("max_gin") / 2 
        	|| query("sen") < query("max_sen") / 2) && query("timer/annie_immortal") + 180 < time())
        {
                message_vision(HIW"\n苏小晓凝眉垂首，衣裳无风自动，泛起一层淡淡浅浅的波光。\n"HIC"微光上漾着圈圈涟漪，将$N衬得有似天女一般，令人不敢轻犯。\n\n"NOR, me);
                set("timer/annie_immortal",time());
                tar = query_enemy();
                for (i=0;i<sizeof(tar) ;i++ )
                        tar[i]->remove_killer(me);
                set("immortal",1);
                set("NO_KILL","苏小晓的衣衫泛着一层淡青色的光芒，将你推到三尺之外。\n");
                set("resistance/kee",100);      // 用来拦阻一些直击rascal skill,像博浪一击 ; annie.
                set("resistance/gin",100);
                set("resistance/sen",100);
                call_out("do_ck",20,tar);
                return ;
        }

        if (query("immortal"))
        {
                tar = query_enemy();
                for (i=0;i<sizeof(tar) ;i++ )
                        tar[i]->remove_killer(me);
        }

    	tar = all_inventory(target);
        if (sizeof(tar) < 1)
                return;

        for (i=0;i<sizeof(tar) ;i++ )
        {
        	item = tar[i];
            if(item->query("skill_type") && !item->query("owner") && !item->query_temp("owner")) {
	        	message("vision",HIB"\n一阵微风拂面而过，你似乎看见"+me->name()+"的影子在风中轻轻一晃。\n", environment(me),me);
	        	message("vision",HIB"你揉揉眼，却发现"+me->name()+"依然还在原地，似乎什么都没有发生。\n\n"NOR, environment(me),me);
	            tell_object(target, "你感觉身上一轻，似乎丢了点东西．．\n\n");    	
	            item->move(me);
	            break;
        	}
        }
       return;

}


void die()
{
        object me,owner,enemy,paper,*sy_inv,things;
        int j;
        me = this_object();
        if (!query_temp("last_damage_from"))
        {
            sy_inv = all_inventory(this_object());
            for(j=0;j<sizeof(sy_inv);j++){
                    things = sy_inv[j];
                    destruct(things);
            }
            ::die();
            return;
        }
    	if(objectp(enemy=query_temp("last_damage_from")))
        if(owner=enemy->query("possessed"))
        	enemy = owner;
        
        if (environment(me)->query("short") != "朝阳峰巅" || !REWARD_D->check_m_success(enemy,"绝世芳华"))
        {
                set("reward_npc", 0);
                sy_inv = all_inventory(this_object());
                for(j=0;j<sizeof(sy_inv);j++){
                        things = sy_inv[j];
                        destruct(things);
                }
                ::die();
                return;
        }
        message_vision(CYN"\n$N仰头看向天空，幽幽的叹了口气。
$N说道：嗯，也就这样了。
$N说道：随缘聚散，无情来去，不落言诠，不坠情障……
$N说道：那还是小时的话，总还是要……不改初心的吧……\n\n"NOR,me,enemy);
        enemy->set("annie/demon_killed_suu",1);
	//	REWARD_D->riddle_done(enemy,"欲望",100,1);
        ::die();
        return;
}



 
/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

