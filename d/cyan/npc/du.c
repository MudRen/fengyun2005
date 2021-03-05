// ; annie 07.2003
// dancing_faery@hotmail.com
// 
// 八部众之迦楼罗王 香销茶尽 杜君山 
// EXP 8M KEE 24K GIN/SEN 16K RESIST/ALL 60
// STR 100 DMG 25 ATTACK 71K DODGE 80K PARRY 71K
// 99% follow rules.

// A/P：等于标准8M。D：高于标准8M。此人可TK。

inherit NPC;
#include <ansi.h>
#include <combat.h>
void smart_fight();

void create()
{
        object armor,weapon;
        set_name("杜君山", ({ "du junshan","du"}) );
        set("gender", "男性" );
        set("title",YEL"大光明教 "NOR CYN"迦楼罗王"NOR);
        set("nickname",HIG"香销茶尽"NOR);
        set("attitude","friendly");

        set_temp("condition_type",NOR CYN" <吹笛中>"NOR);

        set("long",
                "他正侧对着你，专注于手中的叶笛，满头的长发在风中飞扬飘舞，\n与萧萧而下的落木融成了一幅绝美的景象。\n彼汾沮洳，言采其莫。彼其之子，美无度，美无度，殊异乎公路。\n"
                );
        set("class","legend");
    set("combat_exp", 8000000); 
    set("score", 10000);
        set("fle",50);
        set("cor",40);
        set("cps",30);
        set("str",40);
        set("per",200);
        set("force",2500);
        set("max_force",2500);
        set("force_factor",130+random(100));
        set("atman",1500);
        set("max_atman",1500);
        set("mana",1500);
        set("max_mana",1500);

        set("no_fly",1);
        set("no_arrest",1);
                
        set("resistance/gin",60);
        set("resistance/kee",60);
        set("resistance/sen",60);

        set("max_kee",24000);
        set("max_gin",16000);
        set("max_sen",16000);

        set("chat_chance", 1);
        set("chat_msg", ({
                "杜君山放下叶笛，幽幽轻叹：夫亦空兮，妻亦空，黄泉路上不相逢；朋亦空兮，友亦空，各奔前程路不同．．．\n",
                }) );

        set_skill("demon-blade",240);
        set_skill("blade",200);

        set_skill("demon-steps",200);
        set_skill("fall-steps",340);
        set_skill("anxiang-steps",200);
        set_skill("cloud-dance",200);
        set_skill("move",200);
        set_skill("dodge",200);

        set_skill("demon-force",200);
        map_skill("force","demon-force");

    set_skill("perception",200);

        set_skill("meihua-shou",210);
        set_skill("unarmed", 300);
        set_skill("force", 200);

        set_skill("lingxi-zhi", 170);
        set_skill("spells",200);
        set_skill("parry",200);
        set_skill("kwan-yin-spells",200);
        set_skill("five-steps",180);
        set_skill("move",200);
        
        map_skill("spells","kwan-yin-spells");
        map_skill("unarmed", "lingxi-zhi");
        map_skill("force", "bolomiduo");
        map_skill("dodge","fall-steps");
        map_skill("move","anxiang-steps");
        map_skill("blade","demon-blade");
        map_skill("parry","demon-blade");
        
        add_temp("apply/iron-cloth", 200);
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );

        setup();

        carry_object(__DIR__"obj/zhuye")->wield();
        carry_object(__DIR__"obj/bamboocloth")->wear();

    set("reward_npc", 1);
        set("difficulty",7);

}

void init()
{
        if (!is_fighting())
                set_temp("condition_type",NOR CYN" <吹笛中>"NOR);
        add_action("do_answer","answer");
}

object select_opponent()        
{
        object * enemy;
        int i;
        enemy = query_enemy();
        if(!sizeof(enemy)) {
                return 0;
        }
        clean_up_enemy();
        if(!sizeof(enemy)) {
                return 0;
        }
        for(i=0; i<sizeof(enemy); i++)
                if (userp(enemy[i]))
                        return enemy[i]; // focus user. ; annie 6.25.03
        return enemy[random(sizeof(enemy))];
}

int kill_ob(object who)
{
        // 要比silencer更rascal!! >"<
        object me;
        int exp_r,busyst;
        ::kill_ob(who);

        delete_temp("condition_type");

        stop_busy();
        who = select_opponent();        // 选不到就npc好了
        me = this_object();
        if (me->query("combat_exp") * 9 / 8 >= who->query("combat_exp"))        // 9350,%93
                busyst=1;
        else
                busyst=2;

        set("busy_type",busyst);
        set("enemy_id",who->query("id"));


        map_skill("dodge","fall-steps");
        perform_action("dodge.luoyeqiufeng "+query("enemy_id"));

        if (busyst == 1)
        {
                set("class","huashan");
                map_skill("dodge","cloud-dance");
                perform_action("dodge.yexuechuji "+query("enemy_id"));
                set("class","legend");
        }
        else
        {
                ccommand("unwield zhuye");
                map_skill("unarmed","meihua-shou");
                perform_action("unarmed.meihai "+query("enemy_id"));
                ccommand("wield zhuye");
        }

set_temp("a",1);
smart_fight();

        return 1;
}

void smart_fight()
{
        int i;
        int j;
        object *enemy, who,target,me,weapon,wpx;
        string msg;
        who = this_object();
        me=this_object();
        if (who->is_busy()) return;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>2 && enemy[1]->is_zombie()) {
                who->cast_spell("zombie-bolt");
                return;
        }

        target = present(query("enemy_id"),environment());
        if (!target)
                return;

        weapon = present("zhuye",me);
        if (!weapon)
        {
                message_vision(HIG"杜君山身形忽然轻转，飘落到修竹边折下一片细长的竹叶握在手中。\n" NOR,who);
                weapon=new(__DIR__"obj/zhuye");
                weapon->move(me);
                weapon->wield();
        }

        if ((query("kee") < 1500 || query("sen") < 1500 || query("gin") < 1500) && !query("kianmo"))
        {
                set("kianmo",1);
                message_vision(WHT"杜君山的脸上忽然显出一丝绝然之色．．．\n" NOR,who);
                message_vision(HIR"杜君山一咬舌尖，哇的喷出一口鲜血，整个人忽然变得精神百倍。\n" NOR,who);
                this_object()->full_me();
//                "/cmds/imm/full"->main(this_object(),"");
                set("force_factor",query("force_factor")*2);
        call_out("do_kianmo", 4, this_object());
        }

        if (target->query("kee") < 4000 && query("busy_type") == 1)
        {
                map_skill("dodge","demon-steps");
                perform_action("blade.tiandirenmo "+query("enemy_id"));
                map_skill("dodge","fall-steps");
                return;
        }

        if (target->is_busy() && !query_temp("a"))      // Busy tick
                return;
        
        delete_temp("a");

        map_skill("dodge","fall-steps");
        perform_action("dodge.luoyeqiufeng "+query("enemy_id"));

        if (query("busy_type") != 1)
        {
                j=0;
                if (!target->query_temp("weapon") && target->query_skill_mapped("unarmed")=="lingxi-zhi")
                        j=1;
                if (wpx=target->query_temp("weapon"))
                        if (wpx->query("skill_type")=="sword" && target->query_skill_mapped("sword")=="xiaohun-sword")
                                j=1;
                if (wpx=target->query_temp("weapon"))
                        if (wpx->query("skill_type")=="whip" && target->query_skill_mapped("whip")=="xiaohun-whip")
                                j=1;

                if (j < 1 && !target->query_busy())
                {
                        ccommand("unwield zhuye");
                        map_skill("unarmed","meihua-shou");
                        perform_action("unarmed.meihai "+query("enemy_id"));
                        ccommand("wield zhuye");
                        return ;
                }

        }
        else
        {
                set("class","huashan");
                map_skill("dodge","cloud-dance");
                perform_action("dodge.yexuechuji "+query("enemy_id"));
                set("class","legend");
                map_skill("dodge","fall-steps");
        }

        if (!target->is_busy()) // Busy failed,self busy
                return ;

        if (target->query("kee") < 5500)        
        {
                map_skill("dodge","demon-steps");
                perform_action("blade.tiandirenmo "+query("enemy_id"));
                map_skill("dodge","fall-steps");
                return;
        }

        switch (random(5))
        {
        case 0:
                msg = HIY  "$N冷哼一声，竟以"GRN"细长的竹叶"HIY"使出反转流星锤法中的［反背连环］，假意抽身急退，蓦地反身抖手一锤！" NOR;
        me->add_temp("apply/attack",100);
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-100);
                msg = HIY  "$N紧跟一招，另一锤反身又是一锤！！" NOR;
        me->add_temp("apply/attack",100);
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-100);
        msg = HIY  "$N竟然还不回头，两臂一振，再来一锤！" NOR;
        me->add_temp("apply/attack",100);
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-100);
                if (me->query_busy()<2) 
                        me->start_busy(2);
                return;
                break;
        case 1:

                me->add_temp("apply/attack", 150);
                me->add_temp("apply/damage",200);
        msg = HIR  "$N低啸一声，内力聚于双臂，手中的"GRN"细长的竹叶"HIR"幻出无数条绿鳞飞龙，连续三招一气呵成，狂风暴雨般地攻向$n！\n\n第一式！龙现于野！"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIB  "第二式！龙腾四海！！"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIC  "第三式！龙翔九天！！！"NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack", -150);
                me->add_temp("apply/damage", -200);
                if (me->query_busy()<2) 
                        me->start_busy(2);              
                return;
                break;
        case 2:
                me->add_temp("apply/attack",200);
                msg = HIY  "$N手中的"GRN"细长的竹叶"HIY"舞动的速度愈来愈快，吼声愈来愈大\n吼声中"GRN"细长的竹叶"HIY"突然雷霆霹雳般向$n劈出一式『九气破霄』！！！\n" NOR;
                message_vision(msg,me,target);
                msg = HIY  "电光！" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                msg = HIY  "火石！" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                msg = HIY  "撼三山！" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                msg = HIY  "震五岳！" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                msg = HIC  "破九霄！" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                        me->add_temp("apply/attack",-200);
                if (me->query_busy()<2) 
                        me->start_busy(2);              
                return;
                break;
        case 3:
                me->add_temp("apply/attack", 220);
                me->add_temp("apply/damage", 220);
                msg = HIR
                "$N力灌叶梗，手中的"GRN"细长的竹叶"HIR
                "＂叭＂的一声，象条毒龙般向$n钻去！" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/damage", 220);      
                msg = HIR"$N急运真气，大喝一声，手中的"GRN"细长的竹叶"HIR
                        "夹着惊雷之势向$n席卷而去！" NOR;
                COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                me->add_temp("apply/attack", -220);
                me->add_temp("apply/damage", -220-220);
                if (me->query_busy()<2) me->start_busy(2);
                return;
                break;
        case 4:
                me->add_temp("apply/attack", 120);
                msg = YEL  "$N轻叱一声，一振细长的竹叶，竹叶上附着的无数水珠竟然纷纷飞出，\n"CYN"化成"+HIC"  漫"+HIG"  天"+HIY"  花"+HIR"  雨"+NOR CYN" 洒向在场每一个人！\n" NOR;
                message_vision(msg,me);
                weapon->set("name","水珠");
                for (i=0; i<6;i++)
                {
                        msg=HIY"纷飞的水珠射向$n的$l！！"NOR;
                        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
                }
                weapon->set("name","细长的竹叶");
                me->add_temp("apply/attack", -120);
                if (me->query_busy()<2) me->start_busy(2);
                return;
                break;

        }
        return;
}


int do_kianmo()
{
        if (!is_fighting() || query("kee") < 1)
        {
                set("force_factor",query("force_factor")/2);
                return 0;
        }
        receive_damage("kee",query("max_kee")/5);
        receive_damage("sen",query("max_sen")/5);
        receive_damage("gin",query("max_gin")/5);
    call_out("do_kianmo", 4, this_object());
        return 1;
}


int accept_fight(object me)
{
        int flag = 6;   // shui xin feng suu gao du chu sen
        if (me->query("annie/demon_killed_shui"))
                flag--;
        if (me->query("annie/demon_killed_xin"))
                flag--;
        if (me->query("annie/demon_killed_feng"))
                flag--;
        if (me->query("annie/demon_killed_suu"))
                flag--;
        if (me->query("annie/demon_killed_gao"))
                flag--;
        if (me->query("annie/demon_killed_sen"))
                flag--;
        if (flag)
        {
                message_vision(CYN"杜君山停下手中的叶笛，头也不回：“中原武林已危在旦夕，你还有闲暇来找我切磋武艺？”\n"NOR,me);
                message_vision(CYN"$N疑惑的看着杜君山。\n"NOR,me);
                message_vision(CYN"杜君山冷笑道：“莫非你还不知道，上官小仙已在少林、武当、白云、三清、华山，\n在中原的每一个门派中，布下了她最信任的人？”\n("YEL"answer yes"CYN"/"YEL"no"CYN")\n"NOR,me);
                me->set_temp("annie/demon_du",1);
        }
        else
        {
                message_vision(CYN"杜君山叹道：你终于是找来我这里了。\n"NOR,me);
                message_vision(CYN"杜君山叹道：动手罢，击败我后，我自然会将幽灵山庄的暗桩告诉你。\n"NOR,me);
                message_vision(CYN"杜君山看了你一眼，又道：不要顾虑，我下手可绝不会有所留情。\n\n"NOR,me);
                me->set("annie/demon_du",1);
        }
        return 0;
}

int do_answer(string arg)
{
        object me = this_player();
        if (!me->query_temp("annie/demon_du"))
                return 0;
        if (!arg)
                return 0;
        if (arg != "yes" && arg != "no")
                return 0;
        
        me->set_temp("annie/demon_du",0);

        if (arg == "no")
        {
                message_vision(CYN"杜君山哼道：现在你已经知道了。\n"NOR,me);
                return 1;
        }


        if ( !me->query("maze/决战金钱"))
        {
                message_vision(CYN"杜君山哼道：既然知道，你还有空呆在这里？\n"NOR,me);
                return 1;
        }
        message_vision(CYN"$N说道：“但如今上官金虹已死，金钱帮也已土崩瓦解，何来[危在旦夕]？”\n"NOR,me);
        message_vision(CYN"“那为何那些潜伏的人不来阻止你？”杜君山的眼里露出了一丝讥诮的神色：\n"NOR,me);
        message_vision(CYN"“你可知昔日的我教布达拉天王，就是上官小仙？你可知她安排下的并非金钱弟子，而是我教中人？”\n"NOR,me);
                return 1;

}

void unconcious()
{
        die();
        return;
}

void die()
{
        object me,owner,enemy;
        me = this_object();
        if (!query_temp("last_damage_from"))
        {
                ::die();
                return;
        }
    if(objectp(enemy=query_temp("last_damage_from")))
        if(owner=enemy->query("possessed"))
                        enemy = owner;
        if (enemy->query("annie/demon_du") != 1)
        {
                ::die();
                return;
        }
        message_vision(HIR"$N仰天喷出一口鲜血，陡然喝道：住手！\n"NOR,me);
        me->remove_all_killer();
    	me->full_me();    
//      "/cmds/imm/full"->main(me,"");
        set("NO_KILL",1);
        enemy->start_busy(40);  // PK的来乘机杀啊....escape
        start_busy(40);
        call_out("do_exc",2,me,enemy,0);
        return;
}

void do_exc(object me,object target,int count)
{
        string msg;
        string *event_msg = ({
"$N用一种奇怪的眼神看着$n，那眼神中竟带着三分惊讶，三分轻松，三分感激。\n",
"$N捂着胸前致命的伤口，慢慢的对$n说：．．．怪不得你能击败他们。\n",
"是不是觉得奇怪，为何我要将教内私密泄露给你？\n",
"这是一个很长很长的故事．．．\n",
"在九岁那一年，我成了一个孤儿，更早的事，我已经记不得了。\n",
"那时正是三九时节。那年的冬天特别冷，雪花压倒了济南城外的两棵老松。\n",
"当年偶然经过的教主发现了我，拯救了一个本应在饥寒交迫中死去的孤魂。\n",
"教主把我带回大光明教，认真的栽培着我，对我有着再造之恩。\n",
"而在二十四岁成为迦楼罗王之前的那十五年，也是我生命中最快乐的十五年。\n",
"然而在那一年．．．那一年冬天，教主明知我与她座下的侍女袁铮相恋，却把她许给了顾云飞。\n",
"这件事情，教中上下无有不知，却独独瞒着被调在外的我。\n",
"等如昔传信於我，匆忙赶回教中之时，早是雪落尽，人散去．．．\n",
"至上的恩，莫大的恨．．．报恩与复怨的交织，让我在迦楼罗王的这个虚位上，造下无数杀孽。\n",
"我本以为，纵是轮回千载也无法磨灭这样的心情，将永生永世的折磨我．．．\n",
"直到现在，在死去之前，我终于发现自己不再如此执著。\n",
"有些东西只存在于特定的时间内，过了那段时间就没有它存在的意义了。\n",
"在记忆中美好的东西，就让它只存在于记忆中吧。\n",
"——因此，谢谢你，我终于可以解脱。\n\n"});

        msg = event_msg[count];
        message_vision(WHT+msg+NOR,me,target);
        if (count < 17)
                call_out("do_exc",1+random(2),me,target,count+1);
        else
        {
                target->start_busy(1);
                target->set("annie/demon_killed_du",1);
                ::die();
        }
        return;

}

