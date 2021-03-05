// 由于文件太大，本文件被分开。本文件仅由 room_gameover_hj.c 调用。
// 领取奖品（兑换幻境游戏的奖励）。
// naihe 22:56 03-10-23


// #########################################################
// #########################################################
// #########################################################
// 
// 数据类奖品规则说明：(award_data)
//            "score?"  ，需要多少点成绩可以兑换
//            "me?"     ，能够换多少
//            "dt-n?"   ，数据名称
//            "c-name"  ，中文描述，2-4个字，否则不对齐（将会很难看）
//            "all->0?" ，是否仅能兑现一次
//
// 以 gxd 为例，得分必须有100点以上才可以兑换，并且将以 100:1 的兑换率计算得出
//              可以得到多少点 gxd. 它的 "all->0?" 是 "yes"，那么不够兑换的零头
//              将会全部被清除。计算完之后，玩家被 set("shenzhou/pts", 点数)。
//
// 注意，例如 "gxd", "pot" 等位置的ID，仅前8个字符有效。
// 如 贡献度、经验值 等位置的中文名，仅前8个字符有效（即4个汉字）。
//
// 物件类奖品规则说明：（本类奖品已不开放，相关函数已删除！）
//             规则同上，只是多了一个 "fl-set"。
//             它表示在移交这个物件之前，要先对物件进行一些什么样的 set.
//             例如 hsw, 则会设置： hsw->set("huanjing2003_award", 1);
//             不需要任何设置时，可不要 "fl-set" 或把 "fl-set" 的值留空。
//
// 特殊奖品规则说明：
// #define 的2个数值都是特殊奖品所需要的得分值，分别是：
// 
//      KEEP_SKILLS_SCORE, 一次保留技能
//      KEEP_POWER_SCORE,  一次保留力量
//
// #########################################################
// #########################################################
// #########################################################


// ★★★★★★★★★★★★★★★★★★★★★★★★★
// ★★★★★★★★★★★★★★★★★★★★★★★★★
// ★★★★★★★★★★★★★★★★★★★★★★★★★


#define        KEEP_SKILLS_SCORE        500
#define        KEEP_POWER_SCORE         500

#define        award_data        ([ "gxd": ([ "score?":300,"me?":1,"dt-n?":"shenzhou/pts", "c-name":"贡献度","all->0?":"yes" ]),"exp": ([ "score?":1,  "me?":3,"dt-n?":"huanjing2003/exp","c-name":"幻境经验","all->0?":"yes" ]),"pot": ([ "score?":1,  "me?":1,"dt-n?":"huanjing2003/pot","c-name":"幻境潜能","all->0?":"yes" ]), ])

#define        award_obj    ([ ])

// ★★★★★★★★★★★★★★★★★★★★★★★★★
// ★★★★★★★★★★★★★★★★★★★★★★★★★
// ★★★★★★★★★★★★★★★★★★★★★★★★★



string get_prize_name( string n, string id )
{
    if( !n ) n = "神秘奖项";
    if( !id ) id = "??????";
    if( strlen( n ) > 8 ) n = n[0..7];
    if( strlen( id ) > 8 ) id = id[0..7];

    return sprintf( "%s(%s)", n, id );
}


int prize(string arg)
{
    object me = this_player(), temp_obj;
    int amount, temp_int, my_score, i;
    string msg, *key, temp_str;
    mapping award_all, temp_map;

    if( GetAward != "允许" )
        return notify_fail("领取奖品的程序已被巫师关闭，请稍等或询问在线巫师。\n");

    if( query("is_checking") == me->query("id") )
        return notify_fail("现在正在计算你的得分，请稍等再领奖。\n");

    if( me->query_temp("huanjing") )
        return notify_fail("请先以 <YEAH> 指令计算得分，方可领奖。\n");


    my_score = me->query_temp("hj_score");

    // 测试情况时的特别设置。
    if( IS_TEST )
    {
        if( !TEST_AWARD_GXD )
            return notify_fail("现在是测试期间，并且没有任何奖励。请直接离开即可。\n");

        if( !arg || ( arg != "gxd" && arg != "leiji" ) )
            return notify_fail("现在是测试期间，仅有小量奖励，以资鼓励。你的得分是 "+my_score+" 点。\n"
                "换取贡献度：<YEAH!!! gxd>  --> 将你所有得分换成贡献度，每 500 点得分可得 "+TEST_AWARD_GXD+" 点。\n"
                "换取累积技能：<YEAH!!! leiji> --> 将你所有得分换成使用累积技能的机会。每 1000 点换得一次。\n");

        if( arg == "gxd" )
        {
            me->delete_temp("hj_score");
            amount = my_score / 500 * TEST_AWARD_GXD;
            message_vision("$N的得分为 "+my_score+" 点，领取了 "+amount+" 点贡献度。\n",me);
            me->add("fy/pts", amount );
            return 1;
        }

        me->delete_temp( "hj_score" );
        amount = my_score / 1000;
        message_vision("$N的得分为 "+my_score+" 点，领取了 "+amount+" 次使用累积技能的机会。\n",me);
        me->add("huanjing2003/last_skills_times", amount);
        if( me->query("huanjing2003/last_skills_times") > 9 )
        {
            message_vision( "$N的累积技能使用次数已满，最多只能使用 9 次。\n",me);
            me->set("huanjing2003/last_skills_times", 9 );
        }
        return 1;
        // test 状态不做领奖 LOG。
    }
    // 好，正常状态下的领奖程序。
    // 无论有分没分，可以看奖品表。
    if( me->is_busy() ) return notify_fail("你还忙着呢，等有空再领奖吧。\n");
    me->start_busy( 1 );

    if( !arg )
    {

        msg = HIC"=====================================================================
        『幻境·遥远传说之起缘·幽灵显现』    基本奖项列表\n\n"NOR;

        award_all = award_data + award_obj;
        key = keys( award_all );
        if( key && sizeof( key ) > 0 )
        {
            for( i=0;i<sizeof(key);i++ )
            {
                temp_map = award_all[ key[i] ];
                // 处理一下长度，漂亮些
                temp_str = get_prize_name( temp_map["c-name"], key[i] );
                msg += sprintf( "%s %-18s ---- %|4d 得分可换 %|4d \"%s\"。\n",
                    temp_map[ "all->0?" ] == "yes" ? "●" : "○",
                    get_prize_name( temp_map["c-name"], key[i] ),
                    temp_map[ "score?" ], temp_map[ "me?" ],
                    temp_map[ "c-name"] );
            }
        }

        msg += sprintf("
\"●\"标记表示：领取该奖时，将你的得分按兑换率计算后，可得到相应
              数额的奖品，而剩下的“零头”得分将会被清除。
\"○\"标记表示：领取该奖时，扣除奖品需要的得分后，剩下的得分仍有效。

"HIW"请以 %s "HIW"指令领奖，你还有 %d 点的得分。
"HIY"特别奖项列表，请以 %s "HIY"指令查询。
"HIC"=====================================================================\n"NOR,
            HIR"<YEAH!!! ID>"NOR, my_score,
            HIR"<YEAH!!! sp>"NOR,
            );

        me->start_more("", msg,0 );
        return 1;
    }

    if( arg == "sp" )
    {
        msg = sprintf( HIC"=====================================================================
        『幻境·遥远传说之起缘·幽灵显现』    特别奖项列表"NOR"

    在你每一次退出幻境游戏后，一旦计算得分，你的最后一次的所有技能和
力量都会被记录。而每一次你进入幻境游戏时，这些记录都会被削减。其中：

    所有技能记录削减为五分之四，无最高限制，1 级以下遗忘该技能，
                                    无任何技能时，恢复默认设置；
    力量    记录削减为四分之三，最高 30 点，5 点或以下时恢复默认设置。

    你可以在这里以得分兑换，而获得使用这些累积值的机会。当你还拥有某
项的机会时，在你进入游戏后，该项累积值将直接应用到游戏中而不采取默认
的设置。但是，如果你还有某项机会次数，却没有了该项的累积记录或该项数
值太低，你的使用机会的次数不会被扣减，而使用默认设置。

○ 技能保留(skills)  -----  以 %|4d 点得分换取 1 次机会，最多 9 次。
○ 力量保留(power)   -----  以 %|4d 点得分换取 1 次机会，最多 9 次。

"HIW"请以 %s "HIW"指令领奖，你还有 %d 点的得分。
"HIY"你的技能/力量记录，以 <YEAH!!! last> 查询。
"HIC"=====================================================================\n"NOR,
            KEEP_SKILLS_SCORE, KEEP_POWER_SCORE, 
            HIR"<YEAH!!! ID>"NOR, my_score );

        write( msg );
        return 1;
    }
    // 查询已被记录了的各项值。(未削减)
    if( arg == "last" )
    {
        msg = sprintf(  "===============================================\n"
                "你的力量记录为 %d 点，还有 %d 次使用的机会。\n",
                    me->query("huanjing2003/last_power"),
                    me->query("huanjing2003/last_power_times") );

        temp_map = me->query("huanjing2003/last_skills_lv");
        if( !temp_map || !sizeof(temp_map) )
            msg += "你没有技能记录。\n";
        else
        {
            msg += "你的技能记录如下(还有 "+me->query("huanjing2003/last_skills_times")+" 次使用的机会)：\n";
            key = keys( temp_map );
            for( i=0;i<sizeof( key ); i++ )
            {
                msg += sprintf( "%s\t%s\t\t%d\n",
                    key[i],
                    !me->query("huanjing2003/last_skills_name")[key[i]] ?
                        "无效技能" :
                    me->query("huanjing2003/last_skills_name")[key[i]],
                    temp_map[key[i]] );
            }
        }

        msg += "===============================================\n" +
            "这些数值将会在你下一次进入幻境的时候，被系统自动削减。\n"+
            "而如果你还有某项的使用机会，将可以继续使用(被削减后的)对应的项目。\n";

        me->start_more("", msg,0 );
        return 1;
    }

    if( my_score < 1 )
        return notify_fail("你没有任何得分，无法领奖。\n");

    switch( arg )
    {
        case "skills": temp_int = KEEP_SKILLS_SCORE; temp_str = "累积技能"; break;
        case "power": temp_int = KEEP_POWER_SCORE; temp_str = "累积力量"; break;
    }

    if( arg == "skills" || arg == "power" )
    {
        if( my_score < temp_int )
            return notify_fail("你的得分不足 "+temp_int+" 点，无法换取“"+temp_str+"”的奖励。\n");

        if( me->query("huanjing2003/last_"+arg+"_times") >= 9 )
            return notify_fail("你已有 9 次或以上使用“"+temp_str+"”的机会了。\n");

        // OK，可以换
        me->add("huanjing2003/last_"+arg+"_times", 1 );
        me->set_temp("hj_score", my_score - temp_int );

        message_vision( "$N以 "+temp_int+" 点得分换下了一次“"+temp_str+"”的机会。\n", me);
        hj_log_file( sprintf("\n%s(%s)领奖--\"%s\"1次(需%d分)。(%s)\n",
            me->query("name"), getuid(me), temp_str, temp_int, ctime_format() ) );
        return 1;
    }
    // 下面是普通奖品系列。
    // 判断数据类奖品。
    if( !undefinedp( award_data[arg] ) )
    {
        temp_map = award_data[arg];
        // "gxd": ([ "score?":100,"me?":1,"dt-n?":"shenzhou/pts", "c-name":"贡献度","all->0?":"yes" ]),
        if( my_score < temp_map[ "score?" ] )
            return notify_fail("你的得分不足以领取这个奖项。\n");
        temp_str = temp_map[ "c-name" ];
        // 一次领奖
        if( temp_map[ "all->0?" ] == "yes" )
        {
            // 计算可领奖次数
            temp_int = my_score / temp_map[ "score?" ];
            // 计算得奖总数
            temp_int *= temp_map[ "me?" ];
            // LOG
            message_vision( sprintf("$N把所有的得分用来换取了 %d 点%s。\n",
                temp_int, temp_str), me );
            hj_log_file( sprintf("\n%s(%s)领奖--\"%s\"%d点(一次性%d分)。(%s)\n",
                me->query("name"), getuid(me), temp_str, temp_int, 
                me->query_temp("hj_score"), ctime_format() ) );
            // 设置
            me->add( temp_map[ "dt-n?" ] , temp_int );
            me->delete_temp("hj_score");
            return 1;
        }
        // 非一次领奖
        // 计算次数
        temp_int = temp_map[ "me?" ];
        // 这里的 my_score 用意已改，作为领奖需要的得分值。
        my_score = temp_map[ "score?" ];
        message_vision( sprintf( "$N以 %d 点得分换取了 %d 点%s。\n",
            my_score, temp_int, temp_str), me);
        hj_log_file( sprintf("\n%s(%s)领奖--\"%s\"%d点(需%d分)。(%s)\n",
            me->query("name"), getuid(me), temp_str, temp_int, 
            my_score, ctime_format() ) );
        me->add( temp_map[ "dt-n?" ] , temp_int );
        me->add_temp( "hj_score", -my_score );
        return 1;
    }
    write("没有这个奖品。请输入 <YEAH!!!> 查询普通奖项，或 <YEAH!!! sp> 查询特别奖项。\n");
    return 1;
}
