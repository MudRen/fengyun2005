// This program is a part of NT MudLIB
inherit NPC;
inherit F_VENDOR;
#include <ansi.h>


int get_reward();
mixed ask_gift();
mixed ask_gift1();
mixed ask_gift2();
mixed ask_gift3();
mixed ask_gift4();
mixed ask_gift5();
mixed ask_gift6();

void create()
{
	 object cloth;
        set_name(HIM "礼物天使" NOR, ({ "gift angel", "tian shi", "gift", "angel", "liwu" }));
        set("long", @LONG
礼物天使，负责风云节庆期间礼物发放的天使。
LONG);
        set("gender", "女性" );
        set("age", 18);
        set("attitude", "friendly");
        set("max_gin", 5000);
        set("max_kee", 5000);
        set("max_sen", 5000);
        set("force", 5000);
        set("max_force", 5000);
        set("force", 5000);
        set("enforce", 350);
        set("str", 50);
        set("int", 50);
        set("con", 50);
        set("dex", 50);
        set("combat_exp", 1200000);

        set("inquiry", ([
                "节日礼物" : (: get_reward :),
                "礼物" : (: get_reward :),
/*
                "gift" : (: ask_gift :),
                // "国庆礼物" : (: ask_gift1 :),
                // "会员体验" : (: ask_gift2 :),
                // "元旦礼物" : (: ask_gift3 :),
                "春节礼物" : (: ask_gift4 :),
                // "春节特殊礼物" : (: ask_gift5 :),
                // "新人福利" : (: ask_gift6 :),
*/
        ]));
        set("vendor_goods", ([  
                 "/obj/wiz_toy/lvyi.c"         :10,
            //  "/obj/wiz_toy/qingshiling.c"         :10,
            ]) );

        	

        setup();
       cloth=carry_object("/obj/armor/cloth");
	cloth->set_name(MAG"霓裳羽衣"NOR, ({ "nishang yuyi","yuyi"}) );
	cloth->set("long","这是一件霓裳羽衣(nishang yuyi)  婷婷袅袅，锦簇花攒。\n");
	cloth->set("value",0);
	cloth->wear();
}
void reset()
{
        set("vendor_goods", ([  
                 "/obj/wiz_toy/lvyi.c"         :10,
              "/obj/wiz_toy/qingshiling.c"         :10,
              	  "/obj/generate/boots_110_18.c"         :10,
"/obj/generate/boots_110_8.c"         :10,
"/obj/generate/boots_130_19.c"         :10,
"/obj/generate/boots_130_9.c"         :10,
"/obj/generate/boots_150_10.c"         :10,
"/obj/generate/boots_150_20.c"         :10,
"/obj/generate/boots_15_12.c"         :10,
"/obj/generate/boots_15_2.c"         :10,
"/obj/generate/boots_170_11.c"         :10,
"/obj/generate/boots_170_21.c"         :10,
"/obj/generate/boots_25_13.c"         :10,
"/obj/generate/boots_25_3.c"         :10,
"/obj/generate/boots_40_14.c"         :10,
"/obj/generate/boots_40_4.c"         :10,
"/obj/generate/boots_55_15.c"         :10,
"/obj/generate/boots_55_5.c"         :10,
"/obj/generate/boots_70_16.c"         :10,
"/obj/generate/boots_70_6.c"         :10,
"/obj/generate/boots_90_17.c"         :10,
"/obj/generate/boots_90_7.c"         :10,
"/obj/generate/cloth1_130_8.c"         :10,
"/obj/generate/cloth1_150_19.c"         :10,
"/obj/generate/cloth1_25_2.c"         :10,
"/obj/generate/cloth1_40_13.c"         :10,
"/obj/generate/cloth1_70_5.c"         :10,
"/obj/generate/cloth1_90_16.c"         :10,
"/obj/generate/cloth2_110_17.c"         :10,
"/obj/generate/cloth2_110_7.c"         :10,
"/obj/generate/cloth2_15_1.c"         :10,
"/obj/generate/cloth2_15_11.c"         :10,
"/obj/generate/cloth2_170_10.c"         :10,
"/obj/generate/cloth2_170_20.c"         :10,
"/obj/generate/cloth2_55_14.c"         :10,
"/obj/generate/cloth2_55_4.c"         :10,
"/obj/generate/cloth3_130_18.c"         :10,
"/obj/generate/cloth3_150_9.c"         :10,
"/obj/generate/cloth3_25_12.c"         :10,
"/obj/generate/cloth3_40_3.c"         :10,
"/obj/generate/cloth3_70_15.c"         :10,
"/obj/generate/cloth3_90_6.c"         :10,
"/obj/generate/head_110_17.c"         :10,
"/obj/generate/head_110_7.c"         :10,
"/obj/generate/head_130_18.c"         :10,
"/obj/generate/head_130_8.c"         :10,
"/obj/generate/head_150_19.c"         :10,
"/obj/generate/head_150_9.c"         :10,
"/obj/generate/head_15_1.c"         :10,
"/obj/generate/head_15_11.c"         :10,
"/obj/generate/head_170_10.c"         :10,
"/obj/generate/head_170_21.c"         :10,
"/obj/generate/head_25_12.c"         :10,
"/obj/generate/head_25_2.c"         :10,
"/obj/generate/head_40_13.c"         :10,
"/obj/generate/head_40_3.c"         :10,
"/obj/generate/head_55_14.c"         :10,
"/obj/generate/head_55_4.c"         :10,
"/obj/generate/head_70_15.c"         :10,
"/obj/generate/head_70_5.c"         :10,
"/obj/generate/head_90_16.c"         :10,
"/obj/generate/head_90_6.c"         :10,
"/obj/generate/neck_110_17.c"         :10,
"/obj/generate/neck_110_7.c"         :10,
"/obj/generate/neck_130_18.c"         :10,
"/obj/generate/neck_130_8.c"         :10,
"/obj/generate/neck_150_19.c"         :10,
"/obj/generate/neck_150_9.c"         :10,
"/obj/generate/neck_15_1.c"         :10,
"/obj/generate/neck_15_11.c"         :10,
"/obj/generate/neck_170_10.c"         :10,
"/obj/generate/neck_170_20.c"         :10,
"/obj/generate/neck_25_12.c"         :10,
"/obj/generate/neck_25_2.c"         :10,
"/obj/generate/neck_40_13.c"         :10,
"/obj/generate/neck_40_3.c"         :10,
"/obj/generate/neck_55_14.c"         :10,
"/obj/generate/neck_55_4.c"         :10,
"/obj/generate/neck_70_15.c"         :10,
"/obj/generate/neck_70_5.c"         :10,
"/obj/generate/neck_90_16.c"         :10,
"/obj/generate/neck_90_6.c"         :10,
"/obj/generate/surcoat_110_19.c"         :10,
"/obj/generate/surcoat_110_7.c"         :10,
"/obj/generate/surcoat_130_20.c"         :10,
"/obj/generate/surcoat_130_8.c"         :10,
"/obj/generate/surcoat_150_23.c"         :10,
"/obj/generate/surcoat_150_9.c"         :10,
"/obj/generate/surcoat_15_1.c"         :10,
"/obj/generate/surcoat_15_13.c"         :10,
"/obj/generate/surcoat_170_12.c"         :10,
"/obj/generate/surcoat_170_22.c"         :10,
"/obj/generate/surcoat_25_14.c"         :10,
"/obj/generate/surcoat_25_2.c"         :10,
"/obj/generate/surcoat_40_15.c"         :10,
"/obj/generate/surcoat_40_3.c"         :10,
"/obj/generate/surcoat_55_16.c"         :10,
"/obj/generate/surcoat_55_4.c"         :10,
"/obj/generate/surcoat_70_17.c"         :10,
"/obj/generate/surcoat_70_5.c"         :10,
"/obj/generate/surcoat_90_18.c"         :10,
"/obj/generate/surcoat_90_6.c"         :10,
"/obj/generate/wrists_110_6.c"         :10,
"/obj/generate/wrists_130_7.c"         :10,
"/obj/generate/wrists_150_8.c"         :10,
"/obj/generate/wrists_15_1.c"         :10,
"/obj/generate/wrists_170_9.c"         :10,
"/obj/generate/wrists_25_1.c"         :10,
"/obj/generate/wrists_40_2.c"         :10,
"/obj/generate/wrists_55_3.c"         :10,
"/obj/generate/wrists_70_4.c"         :10,
"/obj/generate/wrists_90_5.c"         :10,
"/obj/generate/wrists_90_5_100.c"         :10,


        ]) );
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}


int get_reward()
{
        object me;
        string ret;
    
        me = this_player();
        ret = FESTIVAL_D->get_reward(me);
        tell_object(me, ret);
        return 1;
}      

mixed ask_gift()
{
        object ob, me = this_player();
        string *lines;
        string file, gift;
        int time1, time2;

        file = read_file(CONFIG_DIR + "gift");
        if (! stringp(file))
        {
                command("say 可惜，天神还没有打算做任务礼物呢！");
                return 1;
        }

        lines = explode(file, "\n");
        file = lines[sizeof(lines) -1];

        if (sscanf(file, "%s %d to %d", gift, time1, time2) != 3)
        {
                command("say 奇怪，礼物怎么不见了，难道是天神在作怪？！");
                return 1;
        }

        if( me->query("gifter/"+time1) )
        {
                command("say 呵呵～这就是您的不是了！我已经给过您礼物了啊！");
                return 1;
        }

        if (time() < time1 || time() > time2)
        {
                command("say 对不起，你来的不是时候，现在送你礼物，天神会惩罚我的！");
                return 1;
        }

        if (! ob = new(gift))
        {
                 command("say 奇怪，礼物有大问题，你赶快和天神报告吧！");
                 return 1;
        } else
        {
                 me->set("gifter/"+time1, 1);
                ob->move(me, 1);

                message_vision(HIW "$N" HIW "凌空一指，突然天空中一道" HIM "七" HIY "彩" HIR "霞" HIC "光" HIW "笼罩$n，转瞬即逝！\n" NOR,
                               this_object(), me);

                tell_object(me, HIG "你身上好象多了一个礼物（gift），你快看看是什么礼物吧。\n" NOR);
                return 1;
        }
}

mixed ask_gift1()
{
        int td;
        object ob;
        object me = this_player();

        td = time() / 86400;

        if( me->query("gifter/which_day") == td )
                return "你今天已经领过礼物了。";

        tell_object(me, HIY "\n你领取了一个今天的礼物(" HIM "天师护身符" NOR + HIY ")，祝你在风云里玩的愉快！\n" NOR);

 
        return 1;
}
/* 
mixed ask_gift2()
{
        string id, sql;
        int    jointime, endtime, day;
        object me = this_player();


        if( query("gifter/monfee1", me) )
                return "你已经体验过会员了。";

        id=query("id", me);

        if (! MEMBER_D->is_member(id))
        {
                day = time() + 2678400;
                sql = sprintf("INSERT INTO %s SET id = \"%s\", jointime = %d, endtime = %d",
                              "members", id, time(), day);
                DATABASE_D->db_query(sql);
        } else
        {
                jointime = (int)MEMBER_D->db_query_member(id, "jointime");
                if (jointime < 1) jointime = time();

                endtime  = (int)MEMBER_D->db_query_member(id, "endtime");
                if (endtime < 1) day = time() + 2678400;
                else day = endtime + 2678400;

                sql = sprintf("UPDATE %s SET jointime = %d, endtime = %d WHERE id = \"%s\"",
                              "members", jointime, day, id);

                DATABASE_D->db_query(sql);
        }

        set("gifter/monfee1", 1, me);

        tell_object(me, HIY "\n你领取了一个月的(" HIM "会员体验" NOR + HIY ")，祝你在王者归来里玩的愉快！\n" NOR);

        return 1;
}
*/
mixed ask_gift3()
{
        object me = this_player();


        if( me->query("gifter/20081224" ) )
                return "你已经领过元旦礼物了，不要太贪心。:)";

 /*       if (! MEMBER_D->is_valid_member(me))
        {
                addn("combat_exp", 2000000, me);
                addn("potential", 3000000, me);
                addn("experience", 8000000, me);
                addn("time_reward/quest", 86400, me);
        } else
        {
                addn("combat_exp", 10000000, me);
                addn("potential", 6000000, me);
                addn("experience", 3000000, me);
                addn("balance", 500000000, me);
                addn("time_reward/quest", 172800, me);
        }

        set("gifter/20081224", 1, me);
*/
        tell_object(me, HIY "\n天空突现一道金光照耀着你，你冥冥中感觉到在2017年将万事有如神助！\n" NOR);

        return 1;
}

mixed ask_gift4()
{
        string mapsk;
        object me = this_player();


        if( me->query("gifter/20120120") )
                return "你已经领过春节礼物了，不要太贪心。:)";

        me->add("combat_exp", 2000000);
        me->add("potential", 1000000);
       me->set("gifter/20120120",1);
       
                tell_object(me,
HIW"\n"+
"     ┏━━━━━━━━ "HIR"春节快乐"HIW" ━━━━━━━━┓\n"+
"     ┃  ┌──── Happy  New  Year ────┐  ┃\n"+
"     ┃  │                                  │  ┃\n"+
"     ┃  │                                  │  ┃\n");
                if( strlen( me->query("name")) == 1)tell_object(me,
HIW"┃│亲爱的"+me->query("name")+"：│┃\n");
                if( strlen(me->query("name")) == 2)tell_object(me,
HIW"┃│亲爱的"+me->query("name")+"：│┃\n");
                if( strlen(me->query("name")) == 3)tell_object(me,
HIW"┃│亲爱的"+me->query("name")+"：│┃\n");
                if( strlen(me->query("name")) == 4)tell_object(me,
HIW"┃│亲爱的"+me->query("name")+"：│┃\n");
                if( strlen(me->query("name")) == 5)tell_object(me,
HIW"┃│亲爱的"+me->query("name")+"：│┃\n");
        tell_object(me,
HIW"     ┃  │      愿您和您的家人在新的一年    │  ┃\n"+
"     ┃  │  里，健康、快乐、平安！          │  ┃\n"+
"     ┃  │                                  │  ┃\n"+
"     ┃  │             *  *"HIR"r"HIW"*  *            │  ┃\n"+
"     ┃  │          * *"HIR"a"HIW"* "HIG"^"HIY"Y"HIG"^"HIW" *"HIR"i"HIW"* *         │  ┃\n"+
"     ┃  │         *"HIM"m"HIW"*"HIG"^"HIY"Y"HIG"^"HIW"*"HIG"^\\^"HIW"*"HIG"^"HIY"Y"HIG"^"HIW"*"RED"s"HIW"*        │  ┃\n"+
"     ┃  │         "HIG"^"HIY"Y"HIG"^"HIW"*"HIG"\\"HIW"*"RED"e"HIW"*"HIG"/"HIW"*"HIG"l"HIW"*"HIG"/"HIW"*"HIG"^"HIY"Y"HIG"^"HIW"        │  ┃\n"+
"     ┃  │         *"HIG"\\"HIW"*"CYN"t"HIW"*"HIG"|"HIY"Y"HIG"^\\^"HIY"Y"HIG"|"HIW"*"HIG"l"HIW"*"HIG"/"HIW"*        │  ┃\n"+
"     ┃  │        *"MAG"s"HIW"*"HIG"|"HIY"Y"HIG"^\\\\^/^//^"HIY"Y"HIG"|"HIW"*"HIR"a"HIW"*       │  ┃\n"+
"     ┃  │        "GRN"^"YEL"Y"GRN"^\\\\_^\\\\\\//^_//^"YEL"Y"GRN"^"HIW"       │  ┃\n"+
"     ┃  │        "GRN"^\\_^\\_\\_\\//_/_/^_/^"HIW"       │  ┃\n"+
"     ┃  │         "GRN"^^\\_^\\_\\\\/_/^_/^^"HIW"        │  ┃\n"+
"     ┃  │           "GRN"^^\\_ \\// _/^^"HIW"          │  ┃\n"+
"     ┃  │               "GRN"\\_\\_/"HIW"              │  ┃\n"+
"     ┃  │                "GRN"/|\\"HIW"               │  ┃\n"+
"     ┃  │               "GRN"/\\\\/\\"HIW"              │  ┃\n"+
"     ┃  │                                  │  ┃\n"+
"     ┃  │                  "RED"泥潭巫师组恭贺"HIW"  │  ┃\n"+
HIW"     ┃  └─────────────────┘  ┃\n"+
"     ┗━━━━━━━━━━━━━━━━━━━━━┛\n"+
"\n" NOR);

        return 1;
}

mixed ask_gift5()
{
        object me = this_player();

        if( me->query("gifter/20090121") )
                return "你已经领过春节特殊礼物了，不要太贪心。:)";

        tell_object(me, HIY "\n你领取了春节特殊礼物，祝你新年快乐！\n" NOR);

        return 1;
}

mixed ask_gift6()
{
        object me = this_player();
        if( me->query("gifter/20170928") )
                return "你已经领过新人福利了，不要太贪心。:)";

       me->add("max_force", 100);
        me->add("max_gin", 100);
        me->set("gifter/20170928", 1);
        tell_object(me, HIY "\n你领取了新人福利，祝你玩得愉快！\n" NOR);
        return 1;
}
