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
        set("title","斜倚老松"NOR);
        set("nickname",WHT"烟火散尽"NOR);
        set("age", 20+random(10));
        set("attitude","friendly");

        set("long",
                "她薄薄的脂粉画得有些微残，眼睑和腮角染着浅浅的醉痕，眼\n角是淡淡青晕，仿佛春睡初醒，醉意犹在，头发松松挽起，斜\n插一只玳瑁梳子，懒懒的倚于松下，脸上微有愁色。\n"
                );
        set("class","demon");
    	set("score", 10000);
        set("fle",50);
        set("cor",40);
        set("cps",30);
        set("str",20);
        set("per",200);
        set("force",2500);
        set("max_force",2500);
        set("atman",1500);
        set("max_atman",1500);
        set("mana",1500);
        set("max_mana",1500);

        set("no_fly",1);
        set("no_arrest",1);
                
        set("resistance/gin",60);
        set("resistance/kee",60);
        set("resistance/sen",60);
        
                set("NO_KILL","如此娇弱动人的女子，让人怎能忍得下心下手？\n");

        set("max_kee",24000);
        set("max_gin",16000);
        set("max_sen",16000);
        

        set("chat_chance", 1);
        set("chat_msg", ({
                "苏小晓扬起水袖遮在唇边，懒懒的打了一个呵欠。\n",
                "苏小晓叹道：华山派，华山派……枯梅果然是个不中用的东西，这么点小事都办不好。\n",
                "苏小晓垂下头去，望着手中一对泛着淡淡青光的雕花指甲。\n",
                }) );

    set("inquiry", ([
        "教主":   "action苏小晓打了一个呵欠，摇头道：若是要打听这等无聊事情，你大可不必来了。",
        "魔教":   "action苏小晓打了一个呵欠，摇头道：若是要打听这等无聊事情，你大可不必来了。",
        "大光明教":   "action苏小晓打了一个呵欠，摇头道：若是要打听这等无聊事情，你大可不必来了。",
        "西方神教":   "action苏小晓打了一个呵欠，摇头道：若是要打听这等无聊事情，你大可不必来了。",
        "青青":   "action苏小晓顾了你一眼，漫声道：青青么，就是你梦中情人，莫言我不知道。",
        "梦中情人":   "action苏小晓顾了你一眼，漫声道：你梦中情人么，就是青青，莫言我不知道。", // *snicker suu,*escape
        "华山":   "好好的春水罗衫，冰纨天障，传来传去竟传成那样，倒\n还要依着暗青子吃饭……这华山一派，不拜也罢。",
        "华山派":   "好好的春水罗衫，冰纨天障，传来传去竟传成那样，倒\n还要依着暗青子吃饭……这华山一派，不拜也罢。",
        "华真真":   "好好的春水罗衫，冰纨天障，传来传去竟传成那样，倒\n还要依着暗青子吃饭……这华真真嘛，不拜也罢。",
        "枯梅":   "枯梅么？有勇无谋，只给巾帼丢脸，算不得是个英雄。",
        "枯梅大师":   "枯梅么？有勇无谋，只给巾帼丢脸，算不得是个英雄。",
        "春水罗衫":   "春水罗衫在饮雨那里直是无敌，谁知道这代华山弟子竟\n练成那样，比我还更不如，真是不成气候。",
        "冰纨天障":   "春水罗衫在饮雨那里直是无敌，谁知道这代华山弟子竟\n练成那样，比我还更不如，真是不成气候。",
        "暗青子":   "不就是那乱丢垃圾，污人污眼的本事，叫什么漫天花雨\n，直如与人斗嘴斗得唾沫横飞的。",
        "漫天花雨":   "暗器用到漫天花雨这个份上，却也是登峰造极——臭极，烂极。",
         ]) );


        setup();

        carry_object(__DIR__"obj/longskirt")->wear();


        set_temp("buff_type/blocked",1);        // 不動之界

}


int accept_object(object who, object ob)
{
        if (ob->query("name")==CYN"桃花木牌"NOR 
        	&& ob->query("id") == "taohua mupai" 
        	&& (REWARD_D->riddle_check(who,"绝世芳华") >= 6 
        		|| REWARD_D->check_m_success(who,"绝世芳华")))
        {
                command("sigh");
                command("say 命里有时终需有．．．\n");
                remove_call_out("greeting");
                call_out("greeting", 1,who);
                if (environment())
                	environment()->set("boss_out",time());
                return 1;
        }
        return 0;
}


void greeting(object ob)
{
        mapping data;
        
        message_vision(HIG"\n苏小晓慢慢套上了那对雕花指甲，抬起头对你幽幽一笑：动手吧。\n\n"NOR,ob);
        
        REWARD_D->riddle_done(ob,"绝世芳华",100,1);
        
        data = ([
				"name":		"绝世芳华",
				"target":	ob,
				"att_1":	"cps",
				"att_1c":	1,
				"mark":		1,
		]);
		
		REWARD_D->imbue_att(data);
			
        ob = new(__DIR__"suu");
        ob->move(environment());
        destruct(this_object());
}
