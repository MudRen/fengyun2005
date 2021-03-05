// hawktrainer.c
#include <ansi.h>
inherit SMART_NPC;
void followhim(object ob);
int jice();

void create()
{
        set_name("驯鹰人", ({ "hawk trainer","trainer" }) );
        set("gender", "男性" );
        set("age", 34);
        set("long", "他脸上戴着个奇怪的眼罩，看着活象个大熊猫。\n");

        set("class","wolfmount");
        set("inquiry", ([
                "hawk": "公冶长是骗子！这个瘟头鹰就是不听话！\n",
                "苍鹰": "公冶长是骗子！这个瘟头鹰就是不听话！\n",
                "公冶长": "公冶长是骗子！这个瘟头鹰就是不听话！\n",
                "驯鹰":  "据说公冶长是训练(train)高手，不过我照他的方法做怎么都不成。\n",
                "train":  "据说公冶长是训练(train)高手，不过我照他的方法做怎么都不成。\n",
                "训鹰": "笨蛋，是驯鹰不是训鹰。\n",
        
                "进程": (: jice :),

        ]));    
                set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             (: auto_smart_fight(40) :),
        }) );

    
        set("combat_exp", 7000000);
        set("attitude", "friendly");
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "驯鹰人说：等我驯好苍鹰，什么敌人都逃不出手心！\n",
        }) );

        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/eyecover.c")->wear();
        carry_object(__DIR__"obj/leathersleeves.c")->wear();

        auto_npc_setup("wang",300,220,0,"/obj/weapon/","fighter_w","assassin-hammer",1);

}

void init()
{
        object ob;
        ::init();
        if(interactive(ob = this_player()) && !is_fighting() && userp(ob))
        {

                if((string) ob->name() == "公冶长" )
                {
                        
                        remove_call_out("followhim");
                        //message_vision((string) ob->name(),this_object());
                        call_out("followhim", 2, ob);
                        
                }
        }
        //add_action("do_catch","catch");
        add_action("do_kill","kill");
}


void check_status(object ob)
{
        object room;
        room = find_object(AREA_HUASHAN"fupi");

        remove_call_out("check_status");
        if (!objectp(ob) || !present(ob, environment(this_object())))
        {
                
                message_vision(YEL"$N说：公冶长先生哪里去了? \n",this_object());
                message_vision("$N说：我得回去看看我的猎鹰！ \n"NOR,this_object());
                set_leader(0);
                set("chat_chance", 1);
                this_object()->move("/d/huashan/fupi");
                room->delete("item_desc");
                return;
        }
        else
        {
                if((string) ob->name() != "公冶长" )
                {
                        //remove_class_out("check_status");
                        
                        message_vision(YEL"$N对$n大喝道：你不是公冶长！！ 你是哪里来的骗子？！\n", this_object(),ob);
                        message_vision("我得回去看看我的猎鹰！ \n"NOR,this_object());
                        set_leader(0);
                        set("chat_chance", 1);
                        this_object()->move("/d/huashan/fupi");
                        room->delete("item_desc");
                        return;
                }
        }
        message_vision("$N对$n求道：公冶先生，我按您的方法训练了。可猎鹰就是不听话，求求您再给指点指点吧！\n",this_object(),ob);
        call_out("check_status",10,ob);
        return;
}


void followhim(object ob)
{
        object room;
        room = find_object("/d/huashan/fupi");
        if(environment() == room)
                if( present(ob, environment()))
                {       
                        message_vision( HIY"驯鹰人一看见$N，大喜过望：“公冶长先生您终于来了！您再给指点指点吧！”\n"NOR,ob);
                        set_leader(ob);
                        set("chat_chance", 0);
                        call_out("check_status",10,ob);
                }       
}


int do_kill(string arg)
{
    if (arg == "hawk" || arg=="苍鹰")
    {
        message_vision(RED"$N对$n大吼一声：想打我猎鹰的主意！你活得不耐烦了！ \n"NOR,
                       this_object(),this_player());
        this_object()->kill_ob(this_player());
        this_player()->start_busy(2);
        return 1;
    }
    return 0;
}


int jice()
{
        object me,hawk;
        me = this_player();
        hawk = present("big hawk",environment());
        if ( REWARD_D->riddle_check(me,"绝世芳华") < 5 
        	&& !REWARD_D->check_m_success(me,"绝世芳华"))
                return 0;
        if (!hawk)
                return 0;
        if (REWARD_D->riddle_check(me,"绝世芳华") == 5)
                REWARD_D->riddle_set(me,"绝世芳华",6);

        ccommand("stare");
        ccommand("say "HIR"你既然知道了，就休想再活下去！"NOR);
        kill_ob(me);
        hawk->kill_ob(me);
        return 1;
}

void die()
{
        object suu;
        suu = present("big hawk",environment());
        if (query_temp("last_damage_from"))
        if (REWARD_D->riddle_check(query_temp("last_damage_from"),"绝世芳华") == 6 || REWARD_D->check_m_success(query_temp("last_damage_from"),"绝世芳华"))
             if (suu )
            {
                ccommand("emote 挣扎着大叫：小花，去．．．去．．．");
                message_vision(HIC"\n苍鹰似是听懂了人言，呼扇起双翅，向着朝阳峰方向飞去。\n\n"NOR,this_object());
                destruct(suu);
                suu = new(__DIR__"obj/lingbai");
                suu->move(this_object());
        	}
        ::die();
}

