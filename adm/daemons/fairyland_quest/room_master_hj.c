//                标准描述长度示例                                   |
// “幻境”寻宝系列主题之主控地点
// by naihe  2002-10-22
// 巫师可用 <mewiz> 指令进行一些游戏相关的操作。具体请输入 <mewiz> 查询。
// 强制清除所有 幻境 房间内存在之所有物品（除了玩家之外的一切，都将删除）
//   指令 ： <mewiz del_all>   请谨慎使用！！！
// 更改了一下流程  naihe 8:35 03-11-3

// naihe 05-9-7 10:35  V1.7 继续更新

#include <ansi.h>
inherit ROOM;

#include    "npc_obj/hj_settings/obj_list.h"
// 道具及NPC列表

#include    "npc_obj/hj_settings/room_amount_hj.h"
// 随机发放物品时，需要用到这里面一个变量 幻境总房间数 HJ_ROOM_AMOUNT

int is_gameing = 0;
// 游戏当前状态，即“未启动”

#define        KILL_NPC_DISPERSION_TIME     180
#define        KILL_NPC_AMOUNT_MIN          1
#define        KILL_NPC_AMOUNT_RANDOM       3
// 这三个量决定系统在每隔 TIME 秒钟，向游戏内加入  MIN + random( RANDOM ) 个
// 杀戮型的NPC。
// 现在的设置是 3 分钟 1-3 个。 15:18 03-10-18


#define        QUEST_NPC_DISPERSION_TIME    600
// 多少时间就给游戏中发放一个额外的 "quest" 类NPC，
// 即老人、孩童、商人、藏剑生及珠宝客等

#define        ROUND_DISPERSION_TIME        900
// 每隔一段时间没有新玩家进入 hj，那么有必要补充一些物品以防止冷场。
#define        ROUND_DISPERSION_AMOUNT_MIN      20
#define        ROUND_DISPERSION_AMOUNT_RANDOM   6
// 补充的数量范围是 MIN + random( RANDOM )


int dispersion( object me );
int del_all( object me );
void random_dispersion_to_hj( string *dis_list, int times );
void clean_hj();


void c_msg( string msg )
{
    object naihe;
    if( !msg ) return;
/*    naihe = find_player( "naihe" );
    if( !naihe || !userp(naihe) || naihe->query("env/no_hj_wizmsg") )
          CHANNEL_D->do_channel( this_object(), "sys", YEL+ msg + NOR);
    else */  
     CHANNEL_D->do_sys_channel( "sys", HIR"〖幻境系统通知〗："+msg + "\n"NOR); 
}

void create()
{
    set("short",MAG"虚空之境"NOR);
    set("long","

      你 将 进 入 的 是 幻 境 …… 进 入(enter) 吧……

\n");
    set("no_fly",1);
    set("no_fight", 1);
    set("no_steal", 1);
    set("no_magic", 1);
    set("no_sleep_room", 1);
    set("invalid_startroom",1);

    set("exits",([
        "enter":__DIR__"room_readygo_hj",
    ]));

    set("channel_id", HIY"※幻境主控中心※"NOR);
    setup();
}

void init()
{
    if(wizardp(this_player())) add_action("do_mewiz","mewiz");
    add_action("do_nocmds", ({ "scheme", "drop", "put"}) );
}

int do_nocmds()
{
    write("这里禁止使用这个指令。\n");
    return 1;
}

void reset()
{ 
    ::reset(); 
    set("no_clean_up", 1); 
}

int valid_leave(object me, string dir)
{
    if(dir == "enter")
    {
        if( !userp(me) )
            return notify_fail("猪头不得入内。\n");

        //if( !me->query_temp("enter_hj") )
            //return notify_fail("请从幻境正门进入这里，才可以继续进入下一个地方！\n");

        // 允许进入
        // 如果游戏未启动，启动它，并发放物件
        if( !is_gameing )
        {
            remove_call_out("start_game");
            call_out("start_game",1);
        }
        // 无论如何，每隔一段时间就重新发放一次游戏人物或物品，小量
        // 但若有新玩家进入，这个计时会重新开始
        // 并且该函数会判断，若调用时已是非游戏状态(!is_gameing)，则不操作。
        remove_call_out("dispersion_again");
        call_out("dispersion_again", ROUND_DISPERSION_TIME );

        // 1个半小时后，游戏设置为“关闭中”，同时清理所有场内物品
        // 但若有新玩家进入，这个计时会重新开始
        remove_call_out("reset_game");
        call_out("reset_game",6000);

        // 免得造成什么误会
        if( !is_gameing )
            return notify_fail("请稍等数秒，幻境游戏正在启动中……\n");
    }
        return ::valid_leave(me, dir);
}


int dispersion( object me )
{
    int times;

    if( !me || !wizardp(me) ) return 0;
    if( !is_gameing )
    {
        tell_object(me, "游戏状态并不是 启动中 ，请勿随意派发物件。\n");
        return 1;
    }

    times = 50 + random(11);
    tell_object( me, "Ok. 已执行函数，请留意 sys 信息。\n");
    CHANNEL_D->do_sys_channel("sys", sprintf("%s 手动执行幻境游戏主控中心派发随机物件函数(%d 个物件)。", me->query("id"), times));
    random_dispersion_to_hj( obj_list_all, times );
    return 1;
}


int del_all( object me )
{
    if( !me || !wizardp(me) ) return 0;

    tell_object( me, "Ok. 已执行函数，请留意 sys 信息。\n");
    CHANNEL_D->do_sys_channel("sys", sprintf("%s 手动执行幻境游戏主控中心的强制清除所有境内物件函数。", me->query("id") ));
    clean_hj();
    return 1;
}

int do_mewiz(string arg)
{
    object me = this_player();

    if( !arg )
    {
        write("
可使用之强制指令：

<mewiz dispersion>      随机派发 50 -60 个随机物品至所有随机房间里
                            本指令只能在 is_gameing 状态(游戏启动中) 才可以使用。
<mewiz del_all>         强制清除所有 幻境 所有房间内存在的物件（玩家除外）
                            本指令将直接更改游戏状态为 !is_gameing 。

务必谨慎使用！\n");
        return 1;
    }

    if( arg == "dispersion" )
        return dispersion(me);

    if( arg == "del_all" )
        return del_all(me);

    write("指令有误。请直接输入 <mewiz> 指令作查询。\n");
    return 1;
}


// 为了避免玩家在林内游戏过久，东西拣光NPC杀光JOB做光而产生冷场，
// 加入这个函数，一定时间后将会重新变得热闹起来
void dispersion_again()
{
    int times;
    
    remove_call_out("dispersion_again");
    if( !is_gameing )
        return;
    // 如果已是非启动状态，就别理
    times = ROUND_DISPERSION_AMOUNT_MIN + random( ROUND_DISPERSION_AMOUNT_RANDOM );
    c_msg( "幻境游戏已有 "+(ROUND_DISPERSION_TIME/60)+" 分钟无新玩家进入，正在给境内地点补充各类道具或人物(共"+times+"件)。");
    random_dispersion_to_hj( obj_list_all, times);
    call_out("dispersion_again", ROUND_DISPERSION_TIME );  // 一定时间后又来
}

// 游戏启动
void start_game()
{
    int times;

    if( is_gameing ) return;
    // 如果已在启动，不理。不过这个情况除非有人作弊，否则理论上不会发生

    times = 50+random(21);

    c_msg( "幻境游戏自动启动！正在清除残余境内物件……" );
    remove_call_out("clean_hj");
    clean_hj();
    c_msg( "幻境游戏自动启动！正在给境内地点发放各类道具或人物(共"+times+"件)……");
    random_dispersion_to_hj( obj_list_all, times);
    is_gameing = 1;

    // 开始不断地发放杀戮型NPC
    remove_call_out("random_dispersion_killer");
    call_out("random_dispersion_killer", 1);

    // 开始不断地发放“特别”类型的NPC
    remove_call_out("random_dispersion_questnpc");
    call_out("random_dispersion_questnpc", 1);

    remove_call_out("reset_game");
    call_out("reset_game", 6000 );
}


void reset_game()
{
    c_msg( "幻境游戏已经100分钟无人进入了，将自动清理境内所有物件，并恢复游戏为“未启动”。" );
    clean_hj();
}


// 这个函数用于不断地往幻境里添加 quest 型 npc
void random_dispersion_questnpc()
{
    if( !is_gameing ) return;
    random_dispersion_to_hj( ({ __DIR__"npc_obj/hj_npc_quest" }), 1 );

    remove_call_out("random_dispersion_questnpc");
    call_out("random_dispersion_questnpc", QUEST_NPC_DISPERSION_TIME );
}


// 这个函数用于不断地往幻境里添加杀戮型NPC
void random_dispersion_killer()
{
    if( !is_gameing ) return;
    random_dispersion_to_hj( ({ __DIR__"npc_obj/hj_npc_kill" }),
        KILL_NPC_AMOUNT_MIN + random( KILL_NPC_AMOUNT_RANDOM ) );

    remove_call_out("random_dispersion_killer");
    call_out("random_dispersion_killer", KILL_NPC_DISPERSION_TIME );
}

// 此函数发放随机物件，传入两个参数，分别是 物件列表 及 次数(物件个数)
// 执行此函数时，不会自动进行“清除”。请勿随意调用
void random_dispersion_to_hj( string *dis_list, int times )
{
    int i;
    string r, msg;
    object rs, obj;

    if( !dis_list || sizeof(dis_list) < 1 ) return;

    i = times;
    while( i-- )
    {
        r = __DIR__"hj_room"+( 1+random(HJ_ROOM_AMOUNT) );
        rs = find_object( r );
        if( !rs ) rs = load_object( r );

        // 这里不进行 file_size 的判断。
        obj=new( dis_list[random(sizeof(dis_list))] );
        obj->move(rs);
        if(obj->query("msg")) msg=obj->query("msg");
        else msg="忽然一小阵轻烟掠过……这里似乎多了一些什么。\n";
        tell_room( r ,msg);
    }

    if( times < 10 ) return; // 免得连 killer 的发放也不停地报

    c_msg( "幻境游戏随机发放物件完毕，共发放 "+times+" 件各式物品或NPC。" );
}

// 此函数清除幻境世界。
void clean_hj()
{
    int i,j, c1, c2;
    string f, *files;
    object ob;

    is_gameing = 0;
    // 直接恢复游戏状态为 “未启动”
    for( i = 1; i <= HJ_ROOM_AMOUNT; i++ )
    {
        ob = find_object(__DIR__"hj_room"+i);
        if(!ob)
            continue;
        destruct( ob );
        c1 ++;
    }
    // 删除其它物件
    files = get_dir( __DIR__"npc_obj/");
    foreach( f in files )
    {
        f = __DIR__ "npc_obj/" + f;
        if( f[<2..<1] != ".c" )
            continue;
        if( (ob = find_object( f )) )
        {
            destruct( ob );
            c2 ++;
        }
    }
    c_msg( "幻境游戏世界清除，共清理 "+c1+" 个已载入内存的房间；"+c2+" 个游戏参考物件。游戏恢复为“未启动”状态。" );
}
