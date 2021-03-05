//                标准描述长度示例                                   |
// “幻境”寻宝系列主题之退出（统计成绩并奖励）房间
// by naihe  2002-11-01
// 03-10-23  这个和别的文件不同，这个几乎全部改过了，其他的充其量优化
// 代码、改改设置，加JOB减JOB而已，hohoho
// 所以写个日期。


#include <ansi.h>
inherit ROOM;
inherit F_SAVE;
#include <ctime_format_func.h>

// 巫师可以用 <mewiz> 指令设置是否允许玩家领取奖品。具体操作，请输入 <mewiz> 指令获得

// ########################################################
// ########################################################
// ########################################################

#define            HJ_OUTROOM_DATA    "/data/fairyland/outroom_data"
// 存储文件

#define            IS_TEST              0
#define            TEST_AWARD_GXD       1


// 测试状态时，只能以每 500 点得分换取 TEST_AWARD_GXD 点贡献度。
// 并且在测试状态时，将会进行 ID 判断，未登记参与测试的ID，
// 即 "z_test_id_list.h"  的  test_id_list  内未登记的ID，
// 不予记录 log ，以及不能得到分数。

// 若希望在测试状态时不给予任何奖励，此值 set 0.

// ########################################################
// ########################################################
// ########################################################

#include    "z_test_id_list.h"
// 该文件内仅包含一个 string* 变量： test_id_list.


#include     "z_hj_log_func.h"
// 此文件中定义了LOG文件的文件名：HJ1_LOG_FILE
// 以及 hj_log_file(string log_msg) 函数。
// 本文件及 奖品转让处 都使用 hj_log_file() 函数，而不直接使用 log_file() .


// 各类最高分
string
    HighName1 = "无", HighId1 = "--",
    HighName2 = "无", HighId2 = "--",
    HighName3 = "无", HighId3 = "--";

int    HighScore1 = 0, HighScore2 = 0, HighScore3 = 0;


int OkTimes, FailTimes, AllTimes, FindTimes;

string GetAward = "允许";


// 这里调用子目录内的一个价格文件
#include "npc_obj/hj_settings/obj_values.h"

// 这些 id 需要与游戏内道具同步。
// 使用 #define 的方式，是它不会被 restore() 强制恢复，而造成更改时必须
// 先删除 .o 的麻烦。

#define        all_ids        ([ "dx shuijing":"dx","fx zhishi":"fx","tl shuijing":"tl","hg zhijing":"hg", "qd zhishi":"qd","zh zhihe":"zh","fd zhiqi":"fd","qz zhiqi":"qz", "xr shuijing":"xr","kt shuijing":"kt", "cs zhitong":"cs","dw zhiyi":"dw", "wm guo":"wmg","xr guo":"xrg","tq guo":"tqg","dl guo":"dlg","ys guo":"ysg", "sl guo":"slg", "qt jian":"qtj","lq jian":"lqj","by jian":"byj","yd jian":"ydj", "hj jian":"hjj","nl jian":"nlj","xy jian":"xyj","dh jian":"dhj","bs jian":"bsj", "kf sj":"kfsj","by sj":"bysj","ll sj":"llsj","yd sj":"ydsj","gs sj":"gssj","fh sj":"fhsj","dh sj":"dhsj", "hufeng shi":"hfzs","huanyu shi":"hyzs","luolei shi":"llzs","yindian shi":"ydzs","gunshi shi":"gszs","feihuo shi":"fhs","duohun shi":"dhzs","fuhuo shi":"fhzs" ])


string query_save_file()
{
    return HJ_OUTROOM_DATA;
}

void setlong();

int me_ok( object me )
{
    if( !me || !environment(me) || environment(me) != this_object()
      || query("is_checking") != me->query("id")
      || (me->query_temp("huanjing") != "fail" && me->query_temp("huanjing") != "over")
    )
        return 0;
    return 1;
}

void create()
{
    restore();
    set("short",HIW"回归之路"NOR);
    setlong();
    delete("is_checking");
    // 这个一定要
    set("no_fight", "1");
    set("no_fly",1);
    set("no_steal", "1");
    set("no_sleep_room", "1");
    set("no_magic", 1);
    set("invalid_startroom",1);
    set("exits",([
        "out" : __DIR__"room_door_hj",
    ]));
    setup();
}

void init()
{
    if( wizardp(this_player()) )
        add_action("do_mewiz","mewiz");
    add_action("YEAH","YEAH");
    add_action("prize","YEAH!!!");
    add_action("outout", "outout");
    // 禁止指令
    add_action("no_do_cmds", ({ "get", "put", "drop" }) );
}

int do_mewiz(string arg)
{
    object me=this_player();
    string f_name, msg;

    if( !wizardp(me) )
        return 0;
    if( !arg )
        arg = ".";
    f_name = LOG_DIR + get_log_file_name() + ".c";
    if( arg == "cklog" )
    {
        if( IS_TEST )
            msg = "现在是测试状态，默认的LOG文件是："+f_name+"\n";
        else
            msg = "现在是正常状态，现在的LOG文件是："+f_name+"\n";
        me->start_more_file("", f_name ,0);
        write( msg );
        return 1;
    }
    if( arg == "允许" || arg == "不允许" )
    {
        if( GetAward == arg )
            return notify_fail("现在已经是这个设置了。\n");
        GetAward = arg;
        save();
        return notify_fail("设置成功！现在开始，符合条件的玩家 "+GetAward+" 领取奖品。\n请注意，这个设置将会在本房间重载后被取消，而恢复为默认设置。\n");
    }
    write("现在 "+GetAward+" 玩家领取奖品。以指令 <mewiz 允许/不允许> 来更改这个设置。\n现在默认的LOG文件是："+f_name+" 。\n以指令 <mewiz cklog> 快速查看这个文件。\n");
    return 1;
}

void reset()
{ 
    ::reset(); 
    set("no_clean_up", 1); 
}

int valid_leave(object me, string dir)
{
    object *all_mine;
    int temp, i;

    if( query("is_checking") == me->query("id") )
        return notify_fail("现在正在计算你的得分，请稍等再离开。\n");
    all_mine = deep_inventory(me);
    if( all_mine && sizeof( all_mine ) > 0 )
    {
        for(i=0;i<sizeof(all_mine);i++)
        {
            if( all_mine[i] ->query("hj_game") )
            {
                temp = 1;
                break;
            }
        }
    }
    if(temp)
        return notify_fail( HIR"你身上还携带着幻境相关的物品，请先计算得分再离开。\n"
            "若你执意要离开，可使用 outout 指令，那么你的得分及所有携带的幻境物品将被清除。\n"NOR );
    if ( me->query_temp("huanjing") == "fail" || me->query_temp("huanjing") == "over" )
        return notify_fail(HIR"你未曾计算你的游戏得分，请先计算得分再离开。\n"
            "若你执意要离开，可使用 outout 指令，那么你的得分及所有携带的幻境物品将被清除。\n"NOR);
    if ( me->query_temp("hj_score") )
        return notify_fail(HIR"你未曾把你的得分全部兑奖！请先对奖完毕再离开。\n"
            "若你执意要离开，可使用 outout 指令，那么你的得分及所有携带的幻境物品将被清除。\n"NOR);
    return ::valid_leave(me, dir);
}

int outout()
{
    object me = this_player(), *all_mine;
    int i;

    all_mine = deep_inventory(me);
    if( all_mine && sizeof( all_mine ) > 0 )
    {
        for(i=0;i<sizeof(all_mine);i++)
        {
            if( all_mine[i] ->query("hj_game") )
                destruct( all_mine[i] );
        }
    }
    me->delete_temp("hj_score");
    me->delete_temp("huanjing");
    message_vision( HIR"\n$N"HIR"使用了强制指令，离开了这里。\n"NOR, me );
    me->move( query("exits/out") );
    message_vision( "$N走了过来。\n",me );
    return 1;
}

int no_do_cmds()
{
    if( !wizardp( this_player() ) )
    {
        write("在这里你不允许使用这个指令。\n");
        return 1;
    }
    return 0;
}

string get_TOP_pic()
{
    string c1 = HIB, c2 = HIY, c3 = HIC, c4 = HIG;

    return sprintf(c1+"
 ┏━━━━┳━━━━━━━━━━┳━━━━━━┓
 ┃"+c2+"最高总分"+c1+"┃"+c2+"%|20s"+c1+"┃"+c2+"%|12d"+c1+"┃
 ┣━━━━╋━━━━━━━━━━╋━━━━━━┫
 ┃"+c3+"最高得分"+c1+"┃"+c3+"%|20s"+c1+"┃"+c3+"%|12d"+c1+"┃
 ┣━━━━╋━━━━━━━━━━╋━━━━━━┫
 ┃"+c4+"最高效率"+c1+"┃"+c4+"%|20s"+c1+"┃"+c4+"%6|d /小时"+c1+"┃
 ┣━━━━┻━━┳━━━━┳━━┻━┳━━━━┫
 ┃"HIW"总人次%|8d"+c1+"┃"HIC"胜%|6d"+c1+"┃"HIM"败%|6d"+c1+"┃"HIY"宝%|6d"+c1+"┃
 ┗━━━━━━━┻━━━━┻━━━━┻━━━━┛\n"NOR, 

    HighName1+"("+HighId1+")", HighScore1,
    HighName2+"("+HighId2+")", HighScore2,
    HighName3+"("+HighId3+")", HighScore3,
    AllTimes, OkTimes, FailTimes, FindTimes);
}

void setlong()
{
    set("long", "
            "HIW"【 回 归 现 实 之 路 】
"NOR+get_TOP_pic()+HIW"
      来吧，踏上回归现实之路，忘掉你所经历的
    幻境之事，从这里的虚幻中走出，你将回归你那
  美丽灿烂的阳光之地，你将会记得你真正应该的所在。
"NOR"
  计算你的得分与兑换游戏奖励：< "HIG"YEAH"NOR" / "HIY"YEAH!!!"NOR" >\n");
}


// ####################################################
// ############## 以下是计算得分的函数 ################
// ####################################################

int YEAH()
{
    int temp_score;
    object me = this_player();

    temp_score = me->query_temp("hj_score");

    if( !me->query_temp("huanjing") && temp_score )
        return notify_fail("你的得分已经计算过了。请输入 <YEAH!!!> 指令查询领奖。\n");

    if( me->query_temp("huanjing") != "fail" && me->query_temp("huanjing") != "over" )
    {
        me->delete_temp("hj_score");
        return notify_fail("快快回归现实，莫要停留幻境！\n");
    }

    if( query("is_checking") )
        return notify_fail("现在正计算 "+query("is_checking")+" 的得分，请稍等。\n");
    set("is_checking", me->query("id") );

    // 游戏得分单项最高记录
    message_vision(HIW"\n$N开始计算自己的得分……\n\n"NOR,me);
    message_vision(HIC"$N"HIC"的游戏内得分为："HIY+temp_score+HIC" 点。\n"NOR, me);

    if( temp_score > HighScore2 )
    {
        if( me->query_temp("huanjing") == "fail" )
            message_vision(HIY"\n$N"HIY"的游戏任务得分超过了最高记录！只可惜是失败归来的。\n"NOR,me);
        else
        {
            message_vision(HIY"\n$N"HIY"打破了游戏任务得分的单项最高记录！\n"NOR, me);
            me->set("huanjing2003/gift", "打破任务得分单项最高记录");
            HighScore2 = temp_score;
            HighName2 = me->query("name");
            HighId2 = me->query("id");
            setlong();
        }
    }
    write(HIW"\n现在计算你携带的 常规道具物品 加分……\n"NOR);
    remove_call_out("score_tools");
    call_out( "score_tools", 2, me);
    return 1;
}

void score_tools( object me )
{
    if( !me || !me_ok(me) )
    {
        delete( "is_checking" );
        return;
    }

    tell_object( me, "你的各类常规道具物品加分如下：\n\n");
    // 这里用一个很罗嗦的判断来写，虽然比原先的耗N倍资源，又慢，但是
    // 我认为这样有效果，有气氛，就爱这么做。
    remove_call_out("score_tools_go");
    call_out( "score_tools_go", 1, me, 0, 0);
}

void score_tools_go( object me, int score, int hj_obj_amount )
{
    object *inv_me, temp;
    int i, temp_score;
    string temp_id;

    if( !me || !me_ok(me) )
    {
        delete( "is_checking" );
        return;
    }

    inv_me = all_inventory(me);
    if(inv_me && sizeof(inv_me) > 1)
    {
        for(i=0;i<sizeof(inv_me);i++)
        {
            temp = inv_me[i];

            if( !temp ->query("hj_game/obj") )
                continue;

            temp->set("value",0);
            temp_id = temp -> query("id");

            if( !all_ids[temp_id] || !all_values[all_ids[temp_id]] )
                continue;

            hj_obj_amount ++;
            temp_score = all_values[all_ids[temp_id]] / 3;
            if( temp_score < 1 ) temp_score = 1;
            tell_object( me, sprintf("一%s %s(%s) ，可获得 %d 点游戏得分。\n",
            temp->query("unit"),temp->query("name"),temp->query("id"),temp_score));
            destruct(temp);
            score += temp_score;
            remove_call_out("score_tools_go");
            call_out( "score_tools_go", 1, me, score, hj_obj_amount );
            return;
        }
    }

    message_vision("\n$N共有常规道具 "+hj_obj_amount+" 件，得分是 "+score+" 点。\n", me);
    me->add_temp("hj_score", score );
    tell_object( me, HIW"\n现在计算你携带的 特殊物品 加分……\n"NOR);
    remove_call_out("score_special_tools");
    call_out("score_special_tools", 2, me );
}

void score_special_tools( object me )
{
    if( !me || !me_ok(me) )
    {
        delete( "is_checking" );
        return;
    }

    tell_object( me, "你的各类特殊道具物品加分如下：\n\n");
    // 同上边一样，我爱这样做！！！
    remove_call_out("score_sp_tools_go");
    call_out( "score_sp_tools_go", 1, me, 0, 0);
}

void score_sp_tools_go( object me, int score, int hj_obj_amount )
{
    object *inv_me, temp;
    int i, temp_score;
    string temp_id, temp_msg;

    if( !me || !me_ok(me) )
    {
        delete( "is_checking" );
        return;
    }

    inv_me = all_inventory(me);
    if(inv_me && sizeof(inv_me) > 1)
    {
        for(i=0;i<sizeof(inv_me);i++)
        {
            temp = inv_me[i];
            temp_msg = "none";

            if( !temp ->query("hj_game/obj") )
                continue;

            hj_obj_amount ++;

            temp->set("value",0);
            temp_id = temp -> query("id");

            // 国家宝物额外加分
            if(temp_id == "tmxk yyf" || temp_id == "xlsq szl"
              || temp_id == "wm slzj" || temp_id == "sxzy dsg"
            )
            {
                // 若非本人的，或者有 “假”的标记，只加一部分(相对真的来说)。
                if( !temp -> query("host_id")
                  || temp->query("host_id") != me->query("id")
                  || temp->query("fake")
                )
                {
                    temp_score = 500;
                    temp_msg = "并非你要找寻的";
                }
                // 否则就高分
                else
                {
                    // 这个标记是为了防止以 “宝物的累积 -> 一次性带出” 的方法来冲击高分记录的 :)
                    // 虽然现在这样也行，不过这可亏很多了，呵呵。
                    // 更详细的信息可以看 _qxd_.c 的 3 号主文件
                    if( temp->query("this_time_mark") !=
                        me->query_temp("this_time_mark") )
                    {
                        temp_score = 500;
                        temp_msg = "不是你这一次要找寻的";
                    }
                    else
                    {
                        temp_score = 1500;
                        temp_msg = "属于你的";
                        FindTimes ++;
                    }
                }
            }

            // 其他组成部分的额外加分
            if(temp_id=="tm shen" || temp_id=="sz zuoyi" || temp_id=="sz youyi"
              || temp_id=="lq shou" || temp_id=="jy lei" || temp_id=="mh xin"
              || temp_id=="sl jian" || temp_id=="dz shi" || temp_id=="rr shao"
              || temp_id=="hongse baoshi" || temp_id=="lanse baoshi" || temp_id=="lvse baoshi"
            )
            {
                // 若非本人的，扣分！
                if( !temp->query("host_id")
                  || temp->query("host_id") != me->query("id")
                )
                {
                    temp_score = -200;
                    temp_msg = "并非你要找寻的";
                }
                // 否则还是有一点奖励的
                else
                {
                    temp_score = 200;
                    temp_msg = "属于你的";
                }
            }
            // 各族权杖加分
            if( member_array( temp_id, ({ "manye quanzhang", "mengli quanzhang",
                "aiyao quanzhang", "shanguai quanzhang", "juren quanzhang",}) ) != -1
            )
            {
                temp_msg = "神秘的";
                temp_score = 50;
            }
            // 各族宝物加分
            if( member_array( temp_id, ({ "manye baowu", "mengli baowu",
                "aiyao baowu", "shanguai baowu", "juren baowu",}) ) != -1 )
            {
                temp_msg = "珍贵的";
                temp_score = 100;
            }
            // 其他的一律删除，奖励 1 分。
            if(temp_msg == "none" )
            {
                temp_msg = "已无用处的";
                temp_score = 1;
            }
            tell_object( me, sprintf("一%s "+temp_msg+" %s(%s) ，可获得 %d 点游戏得分。\n",
                temp->query("unit"),temp->query("name"),temp->query("id"),temp_score) );
            score += temp_score;
            destruct(temp);
            remove_call_out("score_sp_tools_go");
            call_out( "score_sp_tools_go", 1, me, score, hj_obj_amount );
            return;
        }
    }
    message_vision("\n$N共有特殊物品 "+hj_obj_amount+" 件，得分是 "+score+" 点。\n", me);
    me->add_temp("hj_score", score );
    tell_object( me, HIW"\n现在计算你的最后得分……\n"NOR);
    remove_call_out("score_all");
    call_out("score_all", 2, me );
}


void score_all( object me )
{
    object *inv_me, temp;
    int i, hj_obj_amount, score, temp_score, e_time,o_time, g_time, xiaolv;
    string temp_id, temp_msg, msg = "";

    if( !me || !me_ok(me) )
    {
        delete( "is_checking" );
        return;
    }

    tell_object( me, "你的其他加分以及最后得分如下：\n\n");

    // 级别加分
    temp_score = me->query("huanjing2003/lv") * 20;  // 由50改为20   naihe 05-9-7 10:14
    if( temp_score == 450 )  // 9 级满级
        temp_score = 200;                            // 由500改为200   naihe 05-9-7 10:14
    msg += "级别得分：" + temp_score+" 点。\n";
    score += temp_score;
    temp_score = 0;

    // 气息加分
    temp_score = ( me->query_temp("hj_hp_max")
            -( me->query_temp("hj_hp_max") - me->query_temp("hj_hp") ) ) / 10;
    if( temp_score < 0 ) temp_score = 0;
    msg += "气息得分：" +temp_score+ " 点。\n";
    score += temp_score;
    temp_score = 0;

    // 力量加分
    temp_score = me->query_temp("hj_game_mepower") / 2;
    if( temp_score < 0 ) temp_score = 0;
    msg += "力量得分："+ temp_score +" 点。\n";
    score += temp_score;
    temp_score = 0;

    me->add_temp("hj_score", score );
    tell_object( me, msg );

    // 计算完毕！计算效率
    score = me->query_temp("hj_score");
    e_time = me->query_temp("hj_enter_time");
    o_time = me->query_temp("hj_out_time");
    if( e_time && o_time && o_time > e_time ) g_time = o_time - e_time;

    if( g_time )
    {
        xiaolv = score * 3600 / g_time;
        msg=sprintf("游戏时间共%d小时%d分%d秒，依此推算，$N"HIC"的幻境游戏得分效率为每小时 %d 点！",
            g_time / 3600, g_time % 3600 / 60, g_time % 3600 % 60, xiaolv);
    }
    else
    {
        xiaolv = 0;
        msg = "由于$N"HIC"没有进入或退出游戏的时间记录，无法计算效率。";
    }

    message_vision(HIC"\n$N"HIC"的最终得分是："+score+" 点！\n"+msg+"\n\n"NOR, me);
    if( score > HighScore1 )
    {
        if( me->query_temp("huanjing") == "fail" )
            message_vision(HIY"$N"HIY"的最终得分超过了最高记录，只可惜是失败归来的。\n"NOR, me);
        else
        {
            message_vision(HIY"$N"HIY"打破了总成绩的最高记录！！！\n"NOR, me);
            me->set("huanjing2003/gift", "打破总成绩最高记录");
            HighScore1 = score;
            HighName1 = me->query("name");
            HighId1    = me->query("id");
            setlong();
        }
    }

    if( xiaolv > HighScore3 )
    {
        if( me->query_temp("huanjing") == "fail" )
            message_vision(HIY"$N"HIY"的效率超过了最高记录，只可惜是失败归来的。\n"NOR,me);
        else
        {
            message_vision(HIY"$N"HIY"打破了效率最高记录！\n"NOR, me);
            me->set("huanjing2003/gift", "打破效率最高记录");
            HighScore3 = xiaolv;
            HighName3 = me->query("name");
            HighId3 = me->query("id");
            setlong();
        }
    }

    // 失败否？
    if(me->query_temp("huanjing") == "fail")
    {
        FailTimes ++;
        message_vision(HIR"很遗憾，$N"HIR"是失败归来的，所有得分将作废。\n祝$N"HIR"下次能够取得好成绩，领取更多的奖励！\n"NOR,me);
        // 若是测试时，必须要在ID LIST 内的玩家才记入 LOG.
        if( !IS_TEST || member_array( me->query("id"), test_id_list ) != -1 )
            hj_log_file( sprintf("\n○( %s - %s )\n○  %s(%s) ：游戏 %d 时 %d 分 %d 秒，得分 %d (失败，得分作废)。\n",
                e_time ? ctime_format( e_time ) : "无进入时间记录",
                o_time ? ctime_format( o_time ) : "无退出时间记录",
                me->query("name"), getuid(me), 
                g_time ? g_time / 3600 : 0,
                g_time ? g_time % 3600 / 60 : 0,
                g_time ? g_time % 3600 % 60 : 0,
                me->query_temp("hj_score") ));

        me->delete_temp("hj_score");
    }
    else
    {
        OkTimes++;

        // 若是测试时，必须要在ID LIST 内的玩家才记入 LOG.
        // 成功类的LOG使用实心圆形标记，查看起来清晰。
        // 而这两个LOG都用了标记，是为了在查看时和其他LOG分开，清晰点。
        if( !IS_TEST || member_array( me->query("id"), test_id_list ) != -1 )
            hj_log_file( sprintf("\n●( %s - %s )\n●  %s(%s) ：游戏 %d 时 %d 分 %d 秒，得分 %d 。%s\n",
                e_time ? ctime_format( e_time ) : "无进入时间记录",
                o_time ? ctime_format( o_time ) : "无退出时间记录",
                me->query("name"), getuid(me), 
                g_time ? g_time / 3600 : 0,
                g_time ? g_time % 3600 / 60 : 0,
                g_time ? g_time % 3600 % 60 : 0,
                me->query_temp("hj_score"),
                xiaolv ? "(效率："+ xiaolv +" / 小时 )" : "(效率未知)") );


        if( score > 10000 )
        {
            message_vision("$N的得分是 "+score+" 点，超过了上限，按 10000 点计算。\n", me);
            me->set_temp("hj_score", 10000 );
        }

        message_vision(HIW"恭喜$N"HIW"成功归来，将得到所有的游戏分数！请输入 <YEAH!!!> 指令查询奖品兑换。\n"NOR,me);
    }

    me->delete_temp("huanjing");

    // 记录该玩家本次的技能、力量。
    // 该数据将在下一次进入游戏时被七星灯判断使用，
    // 这里不作任何判断。

    me->set("huanjing2003/last_power", me->query_temp("hj_game_mepower") );
    me->set("huanjing2003/last_skills_name", me->query_temp("hj_game_skills") );
    me->set("huanjing2003/last_skills_lv", me->query_temp("hj_game_damages") );
    // 即使玩家没有该项数值，也设只不过是设个 0 罢了。灯那边会处理。

    me->save();

    delete("is_checking");
    AllTimes ++;
    setlong();
    save();
    // 只有在这里的时候才 save() .

    if( IS_TEST && !TEST_AWARD_GXD )
    {
        message_vision(HIY"\n由于现在是测试期间，并且没有任何奖励，$N"HIY"的得分被清除了。\n\n"NOR, me);
        me->delete_temp("hj_score");
    }

    if( IS_TEST && member_array( me->query("id"), test_id_list ) == -1 )
    {
        message_vision(HIY"\n由于现在是测试期间，并且$N"HIY"没有报名参加测试，$N"HIY"的得分被清除了。\n\n"NOR, me);
        me->delete_temp("hj_score");
    }
}


// ############## 上面是计算得分的函数 ################

// ####################################################
// ############## 以下是领取奖品的函数 ################
// ####################################################

#include "z_gameover_hj.h"

