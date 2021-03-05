//                标准描述长度示例                                   |
// “幻境”系列主题内巫师工具
// by naihe  2002-10-26  于茂名
// 添加更强力的统计数据功能函数，可分类把幻境内物件列表显示，具体参看其函数  02-11-03

#include <ansi.h>

inherit ITEM;

#include "hj_settings/obj_list.h"
#include "hj_settings/room_amount_hj.h"
#include "hj_settings/obj_copy.h"
#include "hj_settings/hj_msg.h"

int query_autoload() { return 1; }


int errs( string arg )
{
    if( !arg ) arg = "haha\n";

    write( arg );
    return 1;
}


void create()
{
    set_name(HIR"幻境2003·巫师工具"NOR, ({"hj wiz_tools","hj tools", "ht", }));
    set_weight(100);
    if (clonep())
        set_default_object(__FILE__);
    else
    {
        set("long", "这是一个用于“幻境”系列主题内的巫师工具。\n它具体支持的指令请用 <clcl> 命令查询。\n");
        set("unit", "个");
        set("value", 0);
    }

// setup();
}

void init()
{
    if(wizardp(this_player()))
    {
        add_action("do_cl","cl");
        add_action("shows","clcl");
        add_action("do_ck","hjck");
        add_action("do_hjfull", "hjfull");
        add_action("do_del_yun", "delyun" );
        if( getuid(this_player()) == "debug" )
        {
            add_action("do_dispersion", "dispersion" );
            add_action("do_delall", "delall");
        }
    }
}

int do_dispersion()
{
    string master_room = HJ_DIR + "room_master_hj";
    write("开始调用主控房间内函数……\n");
    master_room-> dispersion( this_player() );
    return 1;
}

int do_delall()
{
    string master_room = HJ_DIR + "room_master_hj";
    write("开始调用主控房间内函数……\n");
    master_room-> del_all( this_player() );
    return 1;
}

int shows()
{
    write(HIR"下面是本工具所支持的指令详细说明："NOR"
<cl>           自身备好准许进入 幻境 的标记，并移动至 1 号房间
<cl sks / sksall /!sks>  call 幻境里现行的基本技能(随机call) / 全部 /  清除技能
<cl qxd/!qxd>  备好游戏内七星灯(做不了回答问题的支线任务)  /  清除身上的灯
<cl ?>         查询可供复制的物品（各类游戏内道具）名单
<cl ?? 参数>   列出 参数 号房间内所有 NPC/道具/玩家 列表 (参数默认888)
               888 所有物件清单  111 NPC 清单  222 道具清单
               333 玩家清单  444 非游戏内物品或NPC之清单\n");
    write("<cl go 房间号> 移动至几号房间
<cl gr 参数>   移动至其他房间，分别有： enter / master / ready / out
<cl 其他>      将符合名称的道具复制至当前环境，"HIR"本指令仅奈何可用。"NOR"
<cl piao>      复制一张 门票 到当前环境，"HIR"本指令仅奈何可用。"NOR"
<cl msg 信息>  将你输入的信息发送给所有境内房间
<hjck ID / all>    查询 ID / all(境内玩家) 的幻境气息等资料。
<hjfull ID>    full 该 ID hj气息，省略 id 时，full 自身气息
<delyun ID>    清除该 ID 技能运用状态，省略 id 时，清除自身运用技能状态\n");
    
    return 1;
}

int do_hjfull( string id )
{
    object me = this_player(), v;
    if( !id ) v = me;
    else v = present( id, environment(me) );
    if( !v ) return notify_fail("这里没有这个人。\n");
    if( !userp(v) ) return notify_fail("这里没有这个玩家。\n");

    if( v ->query_temp("huanjing") != "start" )
        return notify_fail( v->query("name")+"并不在幻境游戏中。\n");

    v->set_temp("hj_hp", v->query_temp("hj_hp_max") );
    if( v == me ) message_vision( "$N深深地吸了一口密林之气，幻境气息立时饱满了。\n", me);
    else message_vision( "$N拍了拍$n的肩膀，$n立时觉得伤势复原，全身幻境气息澎湃不止。\n", me,v);
    return 1;
}

int do_del_yun( string id )
{
    object me = this_player(), v;
    if( !id ) v = me;
    else v = present( id, environment(me) );
    if( !v ) return notify_fail("这里没有这个人。\n");
    if( !userp(v) ) return notify_fail("这里没有这个玩家。\n");

    if( v ->query_temp("huanjing") != "start" )
        return notify_fail( v->query("name")+"并不在幻境游戏中。\n");

    v->delete_temp("hj_special");

    if( v == me ) message_vision( "$N猛吸一口大气，停下了所有特殊技能的运用。\n",me);
    else message_vision( "$N拍了拍$n的肩膀，$n不由自主地停下了所有特殊技能的运用。\n", me, v);
    return 1;
}


int do_cl(string arg)
{
    object obj,*room_inv,room,me=this_player();
    int i,room_list,room_amount,all_amount,npc_amount,obj_amount,pler_amount,other_amount;
    string *temp,other_room, tmtm, *hj_ip_list = ({});


    int wiz_amount, box_amount, weapon_amount, stone_amount, guo_amount, tools_amount,
        kill_amount, jingling_amount, quest_amount, ashman_amount, ip_amount;

    if(!wizardp(me)) return notify_fail("巫师方可使用本工具。\n");

    temp=({"feng","yu","lei","dian"});
    if(!arg)
    {
        me->set_temp("huanjing","start");
        me->set_temp("this_time_mark", 1+random(9999) );
        me->set_temp("hj_enter_time", time() );
        me->set_temp("hj_hp_max",5000);
        me->set_temp("hj_hp",5000);
        me->set_temp("hj_game_find",temp[ random( sizeof(temp) ) ] );
        me->set_temp("hj_game_mepower",10);
        me->set_temp("hj_score",1);
        if(me->query("id") == "debug")
            me->delete("env/no_hj_wizmsg");
        // 本人不设置此值时，可接收当有玩家进入游戏的系统报告
        obj=new(__DIR__"shenren_ling");
        obj->waiting_delete( 300 );
        obj->move(me);
        me->move( HJ_DIR + "hj_room1");
        if( 1 )
        {
            mapping find_name = ([
                "feng" : HIW"风之国度"NOR,
                "yu"   : HIM"雨之国度"NOR,
                "lei"  : HIC"雷之国度"NOR,
                "dian" : HIG"电之国度"NOR,
            ]);
            me->set_temp( "apply/short", ({ sprintf( "%s %s(%s)"NOR,
                find_name[ me->query_temp( "hj_game_find" ) ],
                me->query("name"), capitalize(me->query("id")) ), })
            );
            me->set_temp( "hj_apply_short", 1 );
        }
        return errs("游戏所需变量已备好。同时携带了一个 5 分钟的神人令，不需要的话可以丢掉它。\n");
    }

    if( arg == "??" ) arg = "?? 888";

    if( arg == "piao" )
    {
        if( getuid(me) != "debug" )
            return errs("本指令只能由奈何执行。\n");
        new( HJ_DIR +"other_obj/obj_menpiao")->move(environment(me));
        message_vision("$N「哇」地大叫一声，地上多了一张幻境的门票。\n",me);
        return 1;
    }

    if( sscanf(arg, "go %d", room_list) )
    {
        if(room_list<1 || room_list> HJ_ROOM_AMOUNT ) return notify_fail("房间标记号为 1-"+HJ_ROOM_AMOUNT+" .\n");
        me->move( HJ_DIR +"hj_room"+room_list);
        return 1;
    }

    if( sscanf(arg, "gr %s", other_room) )
    {
        switch(other_room)
        {
        case "enter": me->move( HJ_DIR +"room_door_hj"); break;
        case "master": me->move( HJ_DIR +"room_master_hj");break;
        case "ready":me->move( HJ_DIR +"room_readygo_hj");break;
        case "out":me->move( HJ_DIR +"room_gameover_hj");    break;
        default:
        write("输入错误，并无此项预设房间。请查正再试。\n");
        return 1;
        }
        return 1;
    }

    if( sscanf(arg, "msg %s", other_room) )
    {
        hj_shout( HIY"\n【幻境系统通知】："NOR+HIG""+other_room+"\n\n"NOR );
        write("已发送信息至所有境内房间。\n");
        return 1;
    }


    if( sscanf(arg, "?? %d", room_list) )
    {
        if(room_list <=HJ_ROOM_AMOUNT && room_list > 0)
        {
        room=find_object( HJ_DIR +"hj_room"+room_list);
        if(!room) return notify_fail(room_list+" 号房间未载入（即无物品）。\n");
        room_inv = all_inventory(room);
        if(!room_inv || sizeof(room_inv) < 1)
            return notify_fail("该房间无任何物件存在。\n");
        write("该房间物件如下（共"+sizeof(room_inv)+"件）：\n");
        for(i=0;i<sizeof(room_inv);i++)
    write(sprintf("%s(%s)  ",room_inv[i]->query("name"),room_inv[i]->query("id")));
        write("\n\n显示完毕。\n");
        return 1;
        }

        if(room_list == 888)
        {
        for(room_list=1;room_list<= HJ_ROOM_AMOUNT;room_list++)
        {
            room=find_object( HJ_DIR +"hj_room"+room_list);
            if(!room) continue;
            room_inv = all_inventory(room);
            if(!room_inv || sizeof(room_inv) < 1) continue;
            write(sprintf("ROOM "HIR"%-2d "NOR"共"HIY"%d"NOR"件-->",room_list,sizeof(room_inv)));
            for(i=0;i<sizeof(room_inv);i++)
            {
                write(sprintf("%s(%s) ",room_inv[i]->query("name"),room_inv[i]->query("id")));

                all_amount++;
                if(interactive(room_inv[i]))
                {
                    pler_amount++;
                    if( wizardp( room_inv[i] ) ) wiz_amount++;
                    if( member_array( query_ip_name( room_inv[i] ), hj_ip_list ) == -1 )
                    {
                    hj_ip_list += ({ query_ip_name( room_inv[i] ) });
                    ip_amount ++;
                    }
                }
                else
                {
                    if(!room_inv[i]->query("hj_game") ) other_amount++;
                    else
                    {
                    if(room_inv[i]->query("hj_game/obj")) obj_amount++;
                    if(room_inv[i]->query("hj_game/npc")) npc_amount++;
                    tmtm = room_inv[i]->query("hj_game/obj");
                    if( tmtm == "box" ) box_amount++;
                    if( tmtm == "tools" ) tools_amount++;
                    if( tmtm == "sword" ) weapon_amount++;
                    if( tmtm == "magic" ) weapon_amount++;
                    if( tmtm == "quest" ) stone_amount++;
                    if( tmtm == "other" ) guo_amount++;
                    tmtm = room_inv[i]->query("hj_game/npc");
                    if( tmtm == "kill" ) kill_amount++;
                    if( tmtm == "other" ) jingling_amount++;
                    if( tmtm == "quest" ) quest_amount++;
                    if( tmtm == "ashman" ) ashman_amount++;
                    }
                }
            }
            write("\n");
            room_amount++;
        }

        write(sprintf("
共有 %d 个房间存在着各式物件，总计 %d 个。其中：

非游戏内物品 %d 个。
玩家 %d 位，其中 %d 位巫师，共有 %d 个IP。
NPC  %d 个 -- 怪物 %d 个，小精灵 %d 个，商贩及特殊型 %d 个，小矮人 %d 个，其他类 %d 个。
道具 %d 个 -- 宝箱 %d 个，道具类 %d 个，剑和水晶 %d 件，
              技能石 %d 颗，果品或宝石 %d 枚，其他各类 %d 个。\n\n",
            room_amount,all_amount,
            other_amount, 
            pler_amount,wiz_amount, ip_amount,
            npc_amount,kill_amount, jingling_amount, quest_amount,ashman_amount,
            npc_amount - (kill_amount+jingling_amount+quest_amount+ashman_amount),
            obj_amount,box_amount, tools_amount, weapon_amount,
            stone_amount, guo_amount,
            obj_amount - ( box_amount+tools_amount
                +weapon_amount+stone_amount+guo_amount) ));

        return errs("这里显示了所有在幻境里的物品。\n");
        }

        if(room_list == 111)
        {
        for(room_list=1;room_list<=HJ_ROOM_AMOUNT;room_list++)
        {
            room=find_object( HJ_DIR +"hj_room"+room_list);
            if(!room) continue;
            room_inv = all_inventory(room);
            if(!room_inv || sizeof(room_inv) < 1) continue;

            all_amount=0;
            for(i=0;i<sizeof(room_inv);i++)
            {
                if(room_inv[i]->query("hj_game/npc"))
                all_amount++;
            }

            if(all_amount >0 )
            {
                write(sprintf("ROOM "HIR"%-2d "NOR"共"HIY"%d"NOR"个-->",room_list,all_amount));
                for(i=0;i<sizeof(room_inv);i++)
                {
                    if(room_inv[i]->query("hj_game/npc"))
                    {
                    npc_amount++;
                    tmtm = room_inv[i]->query("hj_game/npc");
                    if( tmtm == "kill" ) kill_amount++;
                    if( tmtm == "other" ) jingling_amount++;
                    if( tmtm == "quest" ) quest_amount++;
                    if( tmtm == "ashman" ) ashman_amount++;
    write(sprintf("%s(%s) ",room_inv[i]->query("name"),room_inv[i]->query("id")));
                    }
                }
            }
            if(all_amount > 0)
            { write("\n"); room_amount++; }
        }
        write(sprintf("\n共有 %d 个房间存在着游戏内NPC ，总计 %d 个。\n其中怪物 %d 个，小精灵 %d 个，商贩及特殊型 %d 个，小矮人 %d 个，其他人等 %d 个。\n",
            room_amount,npc_amount, kill_amount, jingling_amount, 
            quest_amount,ashman_amount,
            npc_amount-(kill_amount+jingling_amount+quest_amount+ashman_amount) ));
        return 1;
        }

        if(room_list == 222)
        {
        for(room_list=1;room_list<=HJ_ROOM_AMOUNT;room_list++)
        {
            room=find_object( HJ_DIR +"hj_room"+room_list);
            if(!room) continue;
            room_inv = all_inventory(room);
            if(!room_inv || sizeof(room_inv) < 1) continue;

            all_amount=0;
            for(i=0;i<sizeof(room_inv);i++)
            {
                if(room_inv[i]->query("hj_game/obj"))
                all_amount++;
            }

            if(all_amount >0 )
            {
                write(sprintf("ROOM "HIR"%-2d "NOR"共"HIY"%d"NOR"个-->",room_list,all_amount));
                for(i=0;i<sizeof(room_inv);i++)
                {
                    if(room_inv[i]->query("hj_game/obj"))
                    {
                    obj_amount++;
                    tmtm = room_inv[i]->query("hj_game/obj");
                    if( tmtm == "box" ) box_amount++;
                    if( tmtm == "tools" ) tools_amount++;
                    if( tmtm == "sword" ) weapon_amount++;
                    if( tmtm == "magic" ) weapon_amount++;
                    if( tmtm == "quest" ) stone_amount++;
                    if( tmtm == "other" ) guo_amount++;
    write(sprintf("%s(%s) ",room_inv[i]->query("name"),room_inv[i]->query("id")));
                    }
                }
            }
            if(all_amount > 0)
            { write("\n"); room_amount++; }
        }
        write(sprintf("\n共有 %d 个房间存在着游戏内道具 ，总计 %d 个。\n
  其中宝箱 %d 个，道具类 %d 个，剑和水晶 %d 个，
  技能石 %d 颗，果品或宝石 %d 颗，其他各类 %d 个。\n",
            room_amount,obj_amount,
            box_amount, tools_amount, weapon_amount,
            stone_amount, guo_amount,
            obj_amount - ( box_amount+tools_amount
                +weapon_amount+stone_amount+guo_amount) ));
        return 1;
        }

        if(room_list == 333)
        {
        for(room_list=1;room_list<=HJ_ROOM_AMOUNT;room_list++)
        {
            room=find_object( HJ_DIR +"hj_room"+room_list);
            if(!room) continue;
            room_inv = all_inventory(room);
            if(!room_inv || sizeof(room_inv) < 1) continue;

            all_amount=0;
            for(i=0;i<sizeof(room_inv);i++)
            {
                if( interactive( room_inv[i] ))
                all_amount++;
            }

            if(all_amount >0 )
            {
                write(sprintf("ROOM "HIR"%-2d "NOR"共"HIY"%d"NOR"位-->",room_list,all_amount));
                for(i=0;i<sizeof(room_inv);i++)
                {
                    if(interactive(room_inv[i]))
                    {
                    pler_amount++;
                    if( wizardp(room_inv[i]) )
                        wiz_amount++;
                    if( member_array( query_ip_name( room_inv[i] ), hj_ip_list ) == -1 )
                        {
                        hj_ip_list += ({ query_ip_name( room_inv[i] ) });
                        ip_amount ++;
                    }

    write(sprintf("%s(%s) ",room_inv[i]->query("name"),room_inv[i]->query("id")));
                    }
                }
            }
            if(all_amount > 0)
            { write("\n"); room_amount++; }
        }
        write(sprintf("\n共有 %d 个房间有玩家存在 ，总计 %d 位，其中的 %d 位是巫师。\n共有 %d 个IP在游戏中。\n查看玩家详细状态，请使用指令 <hjck> 。\n",room_amount,pler_amount, wiz_amount, ip_amount));
        return 1;
        }


        if(room_list == 444)
        {
        for(room_list=1;room_list<=HJ_ROOM_AMOUNT;room_list++)
        {
            room=find_object( HJ_DIR +"hj_room"+room_list);
            if(!room) continue;
            room_inv = all_inventory(room);
            if(!room_inv || sizeof(room_inv) < 1) continue;

            all_amount=0;
            for(i=0;i<sizeof(room_inv);i++)
            {
                if( !interactive( room_inv[i] ) && !room_inv[i]->query("hj_game"))
                all_amount++;
            }

            if(all_amount >0 )
            {
                write(sprintf("ROOM "HIR"%-2d "NOR"共"HIY"%d"NOR"件-->",room_list,all_amount));
                for(i=0;i<sizeof(room_inv);i++)
                {
                    if( !interactive( room_inv[i] )
                    && !room_inv[i]->query("hj_game") )
                    {
                    other_amount++;
    write(sprintf("%s(%s) ",room_inv[i]->query("name"),room_inv[i]->query("id")));
                    }
                }
            }
            if(all_amount > 0)
            { write("\n"); room_amount++; }
        }
        write(sprintf("\n共有 %d 个房间有非游戏内物件存在 ，总计 %d 件。\n",room_amount,other_amount));
        return 1;
        }

        write("指令有误。请参阅 shows 查询正确用法。\n");
        return 1;
    }

    if( arg == "sksall" )
    {
        me->set_temp("hj_game_skills/hfzj","呼风之技");
        me->set_temp("hj_game_skills/hyzj","唤雨之技");
        me->set_temp("hj_game_skills/llzj","落雷之技");
        me->set_temp("hj_game_skills/ydzj","引电之技");
        me->set_temp("hj_game_skills/fhzj","飞火之技");
        me->set_temp("hj_game_skills/gszj","滚石之技");
        me->set_temp("hj_game_skills/dhzj","夺魂之技");
        me->set_temp("hj_game_damages/hfzj",5+random(95));
        me->set_temp("hj_game_damages/hyzj",5+random(95));
        me->set_temp("hj_game_damages/llzj",5+random(95));
        me->set_temp("hj_game_damages/ydzj",5+random(95));
        me->set_temp("hj_game_damages/fhzj",5+random(95));
        me->set_temp("hj_game_damages/gszj",5+random(95));
        me->set_temp("hj_game_damages/dhzj",5+random(95));

        me->set_temp("hj_game_skills/heal","恢复之技");
        me->set_temp("hj_game_damages/heal",5+random(95));
        write("游戏内所有技能已备好。\n");
        return 1;
    }

    if(arg == "sks")
    {
        me->delete_temp("hj_game_skills");
        me->delete_temp("hj_game_damages");

        if(random(3)) me->set_temp("hj_game_skills/hfzj","呼风之技");
        if(random(3)) me->set_temp("hj_game_skills/hyzj","唤雨之技");
        if(random(3)) me->set_temp("hj_game_skills/llzj","落雷之技");
        if(random(3)) me->set_temp("hj_game_skills/ydzj","引电之技");
        if(random(3)) me->set_temp("hj_game_skills/fhzj","飞火之技");
        if(random(3)) me->set_temp("hj_game_skills/gszj","滚石之技");
        if(random(3)) me->set_temp("hj_game_skills/dhzj","夺魂之技");
        if(random(3)) me->set_temp("hj_game_damages/hfzj",5+random(95));
        if(random(3)) me->set_temp("hj_game_damages/hyzj",5+random(95));
        if(random(3)) me->set_temp("hj_game_damages/llzj",5+random(95));
        if(random(3)) me->set_temp("hj_game_damages/ydzj",5+random(95));
        if(random(3)) me->set_temp("hj_game_damages/fhzj",5+random(95));
        if(random(3)) me->set_temp("hj_game_damages/gszj",5+random(95));
        if(random(3)) me->set_temp("hj_game_damages/dhzj",5+random(95));

        me->set_temp("hj_game_skills/heal","恢复之技");
        me->set_temp("hj_game_damages/heal",5+random(95));
        write("游戏内随机技能已备好。\n");
        return 1;
    }

    if(arg == "!sks")
    {
        me->delete_temp("hj_game_skills");
        me->delete_temp("hj_game_damages");
        write("游戏内技能已清除。\n");
        return 1;
    }

    if(arg == "qxd")
    {
        obj = new(__DIR__"_qxd_");
        obj ->set("my_master",me );
        switch( me->query_temp("hj_game_find") )
        {
            case "feng": obj->set("find_name", "风之国度");break;
            case "yu"  : obj->set("find_name", "雨之国度");break;
            case "lei"  : obj->set("find_name", "雷之国度");break;
            case "dian"  : obj->set("find_name", "电之国度");break;
        }

        obj->move(me);

        write("这灯不能做问“英雄”问题的那个老人的任务。其他正常使用。\n");
        return 1;
    }

    if(arg == "!qxd")
    {
        if(!present("qixing deng",me))
            return notify_fail("你身上没有七星灯。\n");
        destruct(present("qixing deng",me));
        write("已清除掉身上的一个七星灯了。\n");
        return 1;
    }

        
    if(arg=="?")
    {
        write(HIG"
*************************** 可供复制的物件有： *****************************\n"NOR);
        for(i=0;i<sizeof(can_copy);i++)
        {
            write(can_copy[i]+"    ");
        }
        write(HIG"\n\n
****************** 全部可供本工具复制的游戏物件显示完毕。 ******************\n"NOR);
        return 1;
    }

    if( !all[arg] || !all_dir[arg] || !all_set[arg] ) return notify_fail("现在并没有这个物品可以复制。\n");

    write("将要复制的是："+ all[arg] +" .\n");

    if( getuid(me) != "debug" )
        return errs("cl 物品，本指令只能由奈何执行。\n");

    obj = new(__DIR__+all_dir[arg]);
    if(all_set[arg] == 111) i = 0;
    else i = all_set[arg];

//  这个条件有什么用？？？我怎么看不见哪里有这个，当时想什么忘记了，晕
//    if( i != 123)

    obj->setme( i );
    obj->move(environment(me));
    if( arg == "srl" ) obj->waiting_delete( 300 );

    message_vision( "$N「哇」地大叫一声，地上多了一"+obj->query("unit")+"$n。\n",me, obj);
    return 1;
}

string hjck_player_info( object target )
{
    string msg, temp,weapon_m="", tools_m="", quest_m="", other_m="",special_m="", *sks;
    object *all_mine, env;
    int i, a, isks, iwea, itoo, ique, ioth, ispe;

    if( !target || !environment( target ) ) 
        return "无该玩家或无该玩家所处环境(environment)。\n";

    env = environment( target );

    sks = ({"heal","hfzj","hyzj","llzj","ydzj","dhzj","fhzj", "gszj",});

    msg = HIG"=================================================================================\n"NOR;
    msg += HIY"$N "HIY"的幻境内基本信息：\n"NOR;

    msg += sprintf("等级：%d  气息：%d / %d  力量：%d  成绩：%d  地点：%s  寻找：%s  (状态：%s)\n",
        target->query("huanjing2003/lv"),
        target->query_temp("hj_hp"),target->query_temp("hj_hp_max"),
        target->query_temp("hj_game_mepower"),
        target->query_temp("hj_score"), 
        env->query("room_mark") ? env->query("room_mark") + "" : HIR"非境内"NOR,
        target->query_temp("hj_game_find"),
        target->query_temp("huanjing") );

    msg += HIY"技能：\n"NOR;

    for(i=0;i<sizeof(sks);i++)
    {
        if( target->query_temp("hj_game_skills/"+sks[i])
         && target->query_temp("hj_game_damages/"+sks[i]) )
        {
            isks ++;
            if( isks > 3 )
            {
                isks = 1;
                msg += "\n";
            }
            msg += sprintf("%s(%s) : %3d    ",
                target->query_temp("hj_game_skills/"+sks[i]),sks[i],
                target->query_temp("hj_game_damages/"+sks[i]) );
        }
    }

// 计算携带物件

    all_mine = all_inventory( target );
    if( all_mine && sizeof( all_mine ) )
    {
        for( i=0;i<sizeof(all_mine);i++ )
        {
            temp = all_mine[i]->query("hj_game/obj");
            if( !temp ) continue;

            a++;
            if( temp == "sword" || temp == "magic" )
            {
                iwea ++;
                if( iwea > 8 )
                {
                    iwea = 1;
                    weapon_m += "\n";
                }
                weapon_m += all_mine[i]->query("name") + "  ";
            }
            else if( temp == "tools" )
            {
                itoo ++;
                if( itoo > 8 )
                {
                    itoo = 1;
                    tools_m += "\n";
                }
                tools_m += all_mine[i]->query("name") + "  ";
            }
            else if( temp == "quest" )
            {
                ique ++;
                if( ique > 8 )
                {
                    ique = 1;
                    quest_m += "\n";
                }
                quest_m += all_mine[i]->query("name") + "  ";
            }
            else if( temp == "other" )
            {
                ioth ++;
                if( ioth > 8 )
                {
                    ioth = 1;
                    other_m += "\n";
                }
                other_m += all_mine[i]->query("name") + "  ";
            }
            else
            {
                ispe ++;
                if( ispe > 8 )
                {
                    ispe = 1;
                    special_m += "\n";
                }
                special_m += all_mine[i]->query("name") + "  ";
            }
        }
    }

    msg += HIY"\n携带物品(共 "+a+" 件)：\n"NOR;

    if( weapon_m != "" ) msg += "武器类：\n" + weapon_m + "\n";
    if( tools_m != "" ) msg += "道具类：\n" + tools_m + "\n";
    if( quest_m != "" ) msg += "技能石：\n" + quest_m + "\n";
    if( other_m != "" ) msg += "果品及购物宝石类：\n" + other_m + "\n";
    if( special_m != "" ) msg += "其他特殊类：\n" + special_m + "\n";
    msg += HIG"=================================================================================\n"NOR;

    return msg;
}


int do_ck(string arg)
{
    object target, me=this_player(), *env, rooms;
    string msg,hi;
    int i, j, a;

    if(!arg) return notify_fail("本指令可查看某玩家的幻境内的各类详细状态。\n指令：<hjck ID> 查看该ID状态，查看自己时可以\"me\"代替\n指令：<hjck all> 可查阅所有境内玩家的详细状态。\n");

    if( arg == me->query("id") || arg == "me" )
        target = me;

    if( arg != "all" )
    {
        if( !target ) target = find_player( arg );
        if( !target ) return notify_fail("没有这个玩家在线。\n");

        msg = hjck_player_info( target );
        if( !msg ) msg = "读取资料发生错误。\n";
        if( target == me ) msg = replace_string( msg , "$N", "你" );
        else msg = replace_string( msg, "$N", sprintf( "%s(%s)", target->query("name"),
                    target->query("id") ) );

        me->start_more("", msg,0 );
        return 1;
    }

    msg = "下面是所有幻境境内玩家的详细资料：\n\n";

    for( i=1; i<= HJ_ROOM_AMOUNT; i++ )
    {
        rooms = find_object( HJ_DIR + "hj_room" + i );
        if( !rooms ) continue;

        env = all_inventory( rooms );
        if( !env || sizeof( env ) < 1 ) continue;

        for( j=0;j<sizeof( env ); j++ )
        {
            if( !userp(env[j]) ) continue;

            a ++;
            msg += hjck_player_info( env[j] );
            if( env[j] == me ) msg = replace_string( msg , "$N", "你" );
            else msg = replace_string( msg, "$N", sprintf( "%s(%s)",
                 env[j]->query("name"), env[j]->query("id") ) );
        }
    }

    if( !a ) return notify_fail("现在幻境境内并没有任何玩家。\n");

    me->start_more("", msg + "幻境内现共有 "+a+" 位玩家(IP数请以 <cl ?? 333> 指令查询)。\n",0);
    return 1;
}
