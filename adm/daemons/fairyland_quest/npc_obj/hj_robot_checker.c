//                标准描述长度示例                                   |
// 幻境·遥远传说之起缘·幽灵显现 新增人物，用于检测玩家是否 robot.  grin~
// 以奈何现在写ROBOT的臭水平，只能想到这样的写法，不知道这样的问题能
// 不能用 robot 来回答？ grin~
// ROBOT CHECK 程序在 2002 年底左右写成，这里是直接复制过来用的。

// by naihe  2003-10-22  于茂名

#include <ansi.h>
inherit NPC;
#include <set_del_color.h>
string ask_quest_again();
mapping get_question(int times);
string get_flag(string this_times);


#define        IS_TEST            0
// 不要测试就改 0 喽
// 测试时使用  <testquest ID> 启动测试。

#define        PIC_NUMBER        40
#define        AWARD_SCORE        30


int me_ok(object me)
{
    if( !me || me->query_temp("hj_hp") < 1 || me->query_temp("huanjing") != "start"
      || !environment(me) || !environment(me)->query("room_mark")
          || !query("this_time_mark")
      || query("this_time_mark") != me->query_temp("this_time_mark") )
        return 0;

    return 1;
}

void create()
{
    set_name( "蒙面人", ({ "mengmian ren", "mmr" }) );
    set("long", "这是一个蒙着脸面的男人，嗓音沙哑，一副神秘兮兮的样子。\n");
    set("hj_game/npc", "robot_checker");
    set("gender","男性");
    set("age", 41);
    set("no_refresh",1);
    set("inquiry",([
        "question" : (: ask_quest_again :),
        "问题"     : (: ask_quest_again :),
    ]));

    setup();
}

void init()
{
    add_action("do_look", "look");
    add_action("do_ans", "ans");
    add_action("do_test", "testquest");
}

int do_test( string arg )
{
    object who;

    if( !IS_TEST ) return 0;

    if( query("wait_ans") ) 
        return notify_fail("现在正在进行测试。\n");

    if( !arg ) return notify_fail("要对谁进行问题测试？\n");

    message_vision( "$N对着$n说道：“对"+arg+"进行测试问题。”\n", this_player(), this_object() );
    command( "ok" );

    who = present( arg, environment(this_object()) );
    if( !who )
    {
        command("say 这个人不在这里耶。");
        return 1;
    }

    delete("ans_error");
    delete("quest_ok");
    delete("wait_ans");
    delete("ans_over");

    set("checking_player", who );
    remove_call_out("start_check");
    remove_call_out("delete_me");
    call_out("start_check", 1);
    return 1;
}


int do_ans( string arg )
{
    object me = this_player();
    int player_ans;

    if( query("ans_over") ) return 0;

    if( !query("checking_player") || me != query("checking_player")
        || !query("this_time_mark")
        || query("this_time_mark") != me->query_temp("this_time_mark") )
        return notify_fail("关你什么事？又不是问你。\n");

    if( !arg )
    {
        message_vision("$N对着$n大声说道：“我知道了！它根本就不在这里！！！”\n", me, this_object() );
        command( "kick "+me->query("id") );
        command( "say 胡说！就在这里，看仔细点！");
        return 1;
    }


    message_vision("$N对着$n大声说道：“我知道了！它的位置是 "+arg+" ！”\n", me, this_object() );

    if( !query("wait_ans") )
    {
        command("say 急什么，我都还没问你！");
        return 1;
    }

    if( sscanf( arg, "%d", player_ans ) )
    {
        if( player_ans == query("quest_ans") )
        {
            command( "consider" );
            set("quest_ok", 1);
            remove_call_out("delete_me");
            call_out("delete_me", 1);
            return 1;
        }
        command( "hmm " + me->query("id") );
        if( !query("ans_error") )
        {
            set( "ans_error", 1);
            command("say 看仔细点！！！从左往右数！！！没看清就多问我一次(ask mengmian ren about 问题)！！！");
            return 1;
        }
        command( "faint "+me->query("id") );
        set("ans_over", 1);
        remove_call_out("delete_me");
        call_out("delete_me", 1);
        return 1;
    }

    command("say 乱说！看仔细点！");
    return 1;
}


void delete_me()
{
    object me = query("checking_player"), ob = this_object();
    int hp;

    if( IS_TEST )
    {
        message_vision("\n", this_object() );
        if( query("quest_ok") )
            command("say 恩，回答正确。");
        else command("say 错了！是 "+query("quest_ans")+" 才对！");
        delete("wait_ans");
        return;
    }

    if( !me || !me_ok(me) )
        message_vision("$N左右张望了一下，急急离开了。\n", ob );

    else if( query( "quest_ok" ) )
    {
        command( "say “"+delcolor( me->query("name") )+"，好样的！谢谢你了！”\n");
        message_vision("$n拍了拍$N的头，满意地离开了。\n", me, ob );
        hp = AWARD_SCORE + random( AWARD_SCORE );
        me->add_temp("hj_score", hp );
        tell_object( me, HIR"游戏提示：你的得分增加了 "+hp+" 点！\n"NOR);
    }
    else
    {
        ob->move( environment(me) );
        message_vision( "$n对着$N劈头大骂道：“岂有此理，问你那么简单的问题都不会，该罚！”\n说罢，$n对着$N踢了一脚，$N只痛得嗷嗷大叫。\n$n骂道：“我都看出来了，是 "+query("quest_ans")+" 嘛！！！”$n说完，气愤地离开了！\n", me, ob);
        tell_object( me, HIR"游戏提示：你的气息大大降低了！！！\n"NOR );

        hp = me->query_temp("hj_hp");
        hp = hp / 5;
        if( hp < 1 ) hp = 1;
        me->set_temp("hj_hp", hp );
    }

    destruct( ob );
}

int do_look(string arg)
{
    if( !arg || !id(arg) ) return 0;

    write( query("long") );
    return 1;
}


string ask_quest_again()
{
    object me = this_player();
    if( me != query("checking_player") )
        return "不关你事。";

    if( !query("wait_ans") )
        return "急什么，我忘了我要问什么了。";

    command("say 看清楚点啊。");
    return query("quest");
}


void start_check()
{
    mapping question_info;
    object me;
    string shows_all, shows_color, shows_flag;

    if( !environment(this_object() ) ) return;

    me = query("checking_player");
    if( !me || ( !IS_TEST && !me_ok(me) ) ) return;

    question_info = get_question( PIC_NUMBER );

    message_vision("只见一个$n急急忙忙地走了过来，直冲到$N面前，张口就问了一个问题。\n",
        me, this_object() );

    tell_object( me, query("name")+"说道：“"+me->query("name")+"，我有一个问题想请教你，请你"HIR"务必要在三分钟内回答"NOR"我。”\n");

    tell_object( me,  question_info [ "shows_all" ] );
    tell_object( me,  query("name")+"说道：“我看不出来 "+question_info[ "shows_color" ] +" 这个颜色的 "+question_info[ "shows_flag" ] + " 图案在哪里，你能告诉我它在什么位置吗？”\n");
    tell_object( me,  query("name")+"继续说道：“从左往右数，你把它的位置告诉我就行了。”(ans 数字)\n");
    tell_object( me,  query("name")+"不厌其烦地说道：“如果你没看清，你可以问我，我重复一次。”(ask mengmian ren about 问题)\n");

    set( "quest", question_info[ "shows_all" ] + "\n颜色："+ question_info[ "shows_color" ]+" 图案："+question_info[ "shows_flag" ] + " ，请回答它的位置（从左到右数，<ans 数字>）。\n" );
    set( "quest_ans", question_info[ "answer" ] );
    set("wait_ans", 1);
    remove_call_out("delete_me");
    call_out("delete_me", 180 );
}

mapping get_question(int times)
{
    string
*show=({ }),
*flags=({"☆","★","○","●","◎","◇","◆","□","■","△","▲","¤",}),
flag,
*cls=({HIR,HIC,HIG,HIY,HIW,HIM,}),
cl,
*bcls = ({HBRED,HBCYN,HBGRN,HBYEL,HBWHT,HBMAG,}),
bcl,
temp,
shows = "  ";

    string real_flag;
    int i,j,answer,temp_hh;

    if(!times || times < 5 || times > 100)
        times = 100;

    j = random( 6 );
    flag = flags[random(sizeof(flags))];
    cl = cls[ j ];
    bcl = bcls[ j ];

    real_flag = cl+flag+NOR;

    for(i=0;i<times;i++)
    {
        temp = get_flag(real_flag);
        show += ({ temp });
    }

    answer = 1+random(times);

    show[ answer-1 ] = real_flag;

    shows += "\n";
    for(i=0;i<sizeof(show);i++)
    {
        temp_hh ++;
        shows += show[i];
        if( temp_hh >= PIC_NUMBER / 2 )
        {
            temp_hh = 0;
            shows += "\n";
        }
    }
    shows += "\n\n";

    return ([ "shows_color": bcl+"    "+NOR,"shows_flag": flag+NOR,"shows_all" : shows,"answer":answer ]);

/************************************************
 格式说明：需要调用本函数时，需加参数：“次数”。
 返回值元素说明：
 shows_color :  玩家提示，颜色
 shows_flag  :  玩家提示，图案
 shows_all   :  玩家提示，总图
 answer      :  正确答案

演示流程：
1、先得到此函数返回值：
mapping test = SHOOTING_D->get_question(random(100));

2、在调用端操作，以显示至表层：
string shows_all = test[ "shows_all" ];
string shows_color = test[ "shows_color" ];
string shows_flag = test[ "shows_flag" ];
int answer = test[ "answer" ];

write( shows_all );
write("这次的颜色是："+shows_color+"，图案是："+shows_flag+"。\n");

3、正确答案，即 该图案的正确位置，即“answer”值。

*************************************************/

}

string get_flag(string this_times)
{
    string
*flags=({"☆","★","○","●","◎","◇","◆","□","■","△","▲","¤",}),
temp_flag,
*cls=({HIR,HIC,HIG,HIY,HIW,HIM,}),
temp_cls,
temp_wahaha;

    temp_wahaha = cls[random(sizeof(cls))] + flags[random(sizeof(flags))]+NOR;

    while( temp_wahaha == this_times )
        temp_wahaha = cls[random(sizeof(cls))] + flags[random(sizeof(flags))]+NOR;

    if( !random(2) ) temp_wahaha += " ";

    return temp_wahaha;
}
