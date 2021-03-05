// 本文件被 all_room_info_hj.h
// 及 1_room_info_special.h 
// 在  void init() 内调用。

// naihe 0:29 03-10-21


// 函数名、前后 {} 符号在这里都是不需要的，放在这里摆个样子，看着清晰些
//void init()
//{

    object me = this_player();

    if( me->query_temp("huanjing") !="start" && !me->query("hj_game/npc") )
    {
        remove_call_out("get_out_here");
        call_out("get_out_here",1, me);
    }
    // 玩家在游戏时，将保持所有状态饱满。
    if( me->query_temp("huanjing") == "start" )
        full_all( me );

    if( query("room_mark") != 1 && me->query("hj_game/npc") )
        return;
// 如果不是 1 号房间，来的又是 NPC 的话，直接 return 得了，免得
// add_action() 很耗资源。
// 若是NPC，还要进行一些其他的动作，不可以在这里 return 。

    // 禁止的指令
    add_action( "block_cmds", ({
        "exercise", "dazuo", "respirate",
        "tuna", "practice", "lian",  "exert",
        "study", "du", 
        "eat", "chi", "drink", "he", "fu",
        "to", "scheme", "put",
        "paimai", "jiaoyi", "paimai*", "jiaoyi*",
        "kill", "yun", "pfm", "perform", "hit", "throw", "shoot", "steal", "fight",
        "score", "hp", "hp2", "score2", "score3", "scorenew", "jifa", "enable",
        "jiali", "jiajin", "enforce", "enpower", "prepare", "bei", "inventory",
        "xue", "learn", "skills", "cha", "quest", "questobj",
        "wield", "unwield", "wear", "remove", 
        "chat", "chat*", "new", "new*", "menpai", "menpai*", "jiaoyi", "jiaoy*", "rumor", "rumor*",
        "bangpai", "bangpai*", 
    }) );
    add_action("do_look","look");
    add_action("do_get","get");
//}
