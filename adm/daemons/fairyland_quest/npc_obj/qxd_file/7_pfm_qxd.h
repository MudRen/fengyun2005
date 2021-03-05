// for all_cmds_qxd_hj.h
// naihe 21:42 03-10-17
// 给各个技能都加上 pfm  05-9-3 21:25

mapping can_use_pfm( string pfm_id, object me, object target )
{

    // 成功时，返回如下信息，给战斗函数中的 "pfm_info" 变量接收。
    // "name": "技能中文名"
    // "damages": 攻击力
    // "me_busy": 自身忙时
    // "msg_all": 给房子里其他人看的描述
    // "msg_me": 给自己看的描述
    // "msg_target": 给被攻击房看的描述
    // "lost_hp": 自己消耗气息
    mapping pfm_list;
    string *pfm_msg, pfm_skills, pfm_name, pfm_limit;
    int LostHP_pfm = 10, Me_busy = 3+random(3);
    // PFM_LvNeed 在七星灯 1 号文件内以 #define 定义，至少有该等级的技能才能使用 pfm.
    // 以上2个带大写字母的以及 PFM_LvNeed 变量，即唯一判定 pfm 在什么等级能够使用、
    // 自己消耗气息的量、自身的busy 的依据。
    string msg_all, msg_me, msg_target, find_name;
    int damages, damages_skills;
    if( !pfm_id || !me )
        return 0;
    // 绝技列表
    pfm_list = ([
        "kf": ({ "hfzj", "狂风", "feng", }),
        "by": ({ "hyzj", "暴雨", "yu",   }),
        "jl": ({ "llzj", "惊雷", "lei",  }),
        "xd": ({ "ydzj", "迅电", "dian", }),
        "dh": ({ "dhzj", "夺魂", 0,      }),
        "hy": ({ "fhzj", "火焰", 0,      }),
        "js": ({ "gszj", "巨石", 0,      }),
        //"cs": ({ "heal", "重生", 0,      }),  // 取消这个。感觉总是很不好
    ]);
    // 无此绝技存在，返回不可用
    if( undefinedp( pfm_list[ pfm_id ] ) )
        return ([ "err_msg": "你设定的绝技不存在" ]);
    // 那么有此绝技存在，判断玩家自身的条件是否符合
    // 是否懂得对应技能，以及技能等级是否足够
    pfm_msg = pfm_list[ pfm_id ];
    pfm_skills = pfm_msg[0];
    pfm_name = pfm_msg[1];
    pfm_limit = pfm_msg[2];
    // 不懂该技能，返回不可用
    if( !me->query_temp("hj_game_skills/" + pfm_skills )
     || !me->query_temp( "hj_game_damages/" + pfm_skills ) )
        return ([ "err_msg": "你并不懂得「"+pfm_name+"」绝技的技能" ]);
    // 国度技能本国使用
    if( pfm_limit && me->query_temp( "hj_game_find" ) != pfm_limit )
        return ([ "err_msg": "「"+pfm_name+"」绝技只能由本国度子民使用" ]);
    damages_skills = me->query_temp( "hj_game_damages/" + pfm_skills );
    // 等级是否足够、气息是否足够
    if( damages_skills < PFM_LvNeed )
        return ([ "err_msg":"你的技能等级不够，无法使用「"+pfm_name+"」绝技" ]);
    if( me->query_temp("hj_hp") < ( LostHP_pfm * 5 ) )
        return ([ "err_msg":"你的气息太弱，无法使用「"+pfm_name+"」绝技" ]);
    /*
    // 好了！一切OK，可以使用绝技！
    // 如果是恢复技，直接在这里处理。
    if( pfm_id == "cs" )
    {
        int hp_add;
        message_vision( CYN"\n只见$N"NOR+CYN"深深地吸了一口气，看起来精神好多了。\n\n"NOR, me );
        hp_add = me->query_temp( "hj_game_damages/" + pfm_skills );
        hp_add = hp_add*2 + random(hp_add);
        me->add_temp( "hj_hp", hp_add );
        if( me->query_temp( "hj_hp" ) > me->query_temp( "hj_hp_max") )
            me->set_temp( "hj_hp", me->query_temp( "hj_hp_max") );
        me->start_busy( 3+random(8) );
        return 0;  // return 0 时那边就不再处理了。
    }
    */
    if( pfm_id == "dh" )
    {
        // me 无论如何都不 busy
        int target_busy;
        if( target->query_busy() > 3 )
            return ([ "err_msg" : target->query("name")+"还忙得很呢，还是趁机攻击吧" ]);
        if( me->query_temp( "hj_hp" ) < (50+damages_skills) )
            return ([ "err_msg" : "你气息虚弱，无法施展「"+pfm_name+"」绝技" ]);
        message_vision( HIB"\n只见$N"HIB"忽地身形一闪，快速无伦地贴近$n"HIB"，右掌对着$n"HIB"急拍而出！\n"NOR, me, target );
        me->add_temp( "hj_hp", -(damages_skills/3+random(damages_skills/5)) ); // 99lv = 33 + 19, 40lv = 16+8
        // 失败
        // 夺魂技能特殊运用效果  有效抵抗各类夺魂攻击
        if( target->query_temp( "hj_special/sh" ) )
        {
            message_vision( HIB"只听得$N"HIB"四周忽地响起一阵凄厉之声，似是把$N"HIB"保护起来了一般。\n", target );
        }
        else if( !random(10) || random( 100 )+1 > damages_skills )
        {
            message_vision( CYN"$N"NOR+CYN"一惊之下急忙一闪，躲开了$n"NOR+CYN"的攻击。\n\n"NOR, target, me );
        }
        else
        {
            target_busy = 5+random( damages_skills/10 );  // lv40:5+random(4)  lv99:5+random(9)
            tell_object( target, HIR"你一下子被拍个正中，突然全身僵硬，无法动弹！ (造成忙时 "+target_busy+" 秒)\n\n"NOR );
            tell_object( me, HIR+target->query("name")+HIR"被拍个正中，突然两眼发直，整个人呆住了似的。 (造成忙时 "+target_busy+" 秒)\n\n"NOR );
            tell_room( environment(target), HIR+target->query("name")+HIR"被拍个正中，突然两眼发直，整个人呆住了似的。\n\n"NOR, ({ me, target }));
            target->start_busy( target_busy );
        }
        return 0;
    }
    // 确定绝技攻击力
    damages = (damages_skills * 2) + random( damages_skills / 5 );
    // lv40 = 80 + random(8)
    // lv99 = 198 + random( 19 )
    // 效果描述及攻击加成
    find_name = me->query_temp( "hj_game_find");

    switch( pfm_name )
    {
      case "狂风":
        if( find_name == "feng" )
            damages += damages/4;   // lv40 = 100 +, lv99 = 250+
        // 描述
        msg_all = HIW"\n只见$N"HIW"忽地怒目一睁，挺身而立，两手握起咒诀置于胸前，大声叫道：“狂风速来！！！”\n霎时间落叶纷飞，狂风怒吼，从四面八方向着$n"HIW"直扑而至！！！\n\n"NOR;
        msg_me = HIW"\n你双目一睁，挺身而立，两手握起咒诀置于胸前，大声叫道：“狂风速来！！！”\n霎时间落叶纷飞，狂风怒吼，从四面八方向着$n"HIW"直扑而至！！！\n造成了 "HIG+damages+HIW" 点伤害。\n\n"NOR;
        msg_target = HIW"\n只见$N"HIW"忽地双目一睁，挺身而立，两手握起咒诀置于胸前，大声叫道：“狂风速来！！！”\n霎时间落叶纷飞，狂风怒吼，从四面八方向着你直扑而至！！！\n造成了 "HIR+damages+HIW" 点伤害。\n\n"NOR;
        break;
      case "暴雨":
        if( find_name == "yu" )
            damages += damages/4;
        msg_all = HIM"\n只见$N"NOR+HIM"忽地浮身离地，双目微闭，两手往外一分，柔声念道：“密密之雨，请浇洒而下吧！”\n晴朗碧空顿时乌云遍盖，豆大雨点带起劈空之声，一颗颗都对准了$n"NOR+HIM"呼啸而去！！！\n\n"NOR;
        msg_me = HIM"\n你浮身离地，双目闭起，两手往外一分，柔声念道：“密密之雨，请浇洒而下吧！”\n晴朗碧空顿时乌云遍盖，豆大雨点带起劈空之声，一颗颗都对准了$n"NOR+HIM"呼啸而去！！！\n造成了 "HIG+ damages + NOR+HIM" 点伤害。\n\n"NOR;
        msg_target = HIM"\n只见$N"NOR+HIM"忽地浮身离地，双目微闭，两手往外一分，柔声念道：“密密之雨，请浇洒而下吧！”\n晴朗碧空顿时乌云遍盖，豆大雨点带起劈空之声，一颗颗都对准了你呼啸而来！！！\n造成了 "HIR+ damages +NOR+HIM" 点伤害。\n\n"NOR;
        break;
      case "惊雷":
        if( find_name == "lei" )
            damages += damages/4;
        msg_all = HIC"\n忽然只见$N"NOR+HIC"双掌往前一推，暴然喝道：“惊心之雷，响彻四方！！！”\n四处毫无预兆地雷声炸起，声声巨响震人心魄，似有千军万马尽皆朝$n"NOR+HIC"奔袭而去！！！\n\n"NOR;
        msg_me = HIC"\n你双掌往前一推，暴然喝道：“惊心之雷，响彻四方！！！”\n四处毫无预兆地雷声炸起，声声巨响震人心魄，似有千军万马尽皆朝$n"NOR+HIC"奔袭而去！！！\n造成了 "HIG+ damages + NOR+HIC" 点伤害。\n\n"NOR;
        msg_target = HIC"\n忽然只见$N"NOR+HIC"双掌往前一推，暴然喝道：“惊心之雷，响彻四方！！！”\n四处毫无预兆地雷声炸起，声声巨响震人心魄，似有千军万马尽皆朝你奔袭而来！！！\n造成了 "HIR+ damages +NOR+HIC" 点伤害。\n\n"NOR;
        break;
      case "迅电":
        if( find_name == "dian" )
            damages += damages/4;
        msg_all = HIG"\n忽然只见$N"NOR+HIG"右手抬起，一指向天，接着虚画半圆，猛地指向$n"NOR+HIG"！\n随着这一指，天空里竟然劈起一道闪电，夹着沉闷雷声，直打$n"NOR+HIG"而去！！！\n\n"NOR;
        msg_me = HIG"\n你抬起右手，一指向天，接着虚画半圆，暗念咒文，随即指向$n"NOR+HIG"！\n你一指方向，天空里即刻劈起一道闪电，夹着沉闷雷声，直向$n"NOR+HIG"打去！！！\n造成了 "HIG+damages+NOR+HIG" 点伤害。\n\n"NOR;
        msg_target = HIG"\n忽然只见$N"NOR+HIG"右手抬起，一指向天，接着虚画半圆，猛地指向了你！\n随着这一指，天空里竟然劈起一道闪电，夹着沉闷雷声，直向你打了过来！！！\n造成了 "HIR+damages+NOR+HIR" 点伤害。\n\n"NOR;
        break;
      case "火焰":
        msg_all = WHT"\n只听得$N"NOR+WHT"哈哈大笑一声，单掌在身前虚画一圆，一团团"HIR"火焰"NOR+WHT"竟凭空生成，热气逼人！\n紧跟着，$N"NOR+WHT"喝道：“着！”双手连甩，团团火焰立时向着$n"NOR+WHT"激射而去！！！\n\n"NOR;
        msg_me = WHT"\n你哈哈大笑一声，单掌在身前虚画一圆，一团团"HIR"火焰"NOR+WHT"就此凭空生成，热气逼人！\n紧跟着，你大喝了一声“着！”双手连甩，团团火焰立时向着$n"NOR+WHT"激射而去！！！\n造成了 "HIG+damages+NOR+WHT" 点伤害。\n\n"NOR;
        msg_target = WHT"\n只听得$N"NOR+WHT"哈哈大笑一声，单掌在身前虚画一圆，一团团"HIR"火焰"NOR+WHT"竟凭空生成，热气逼人！\n紧跟着，$N"NOR+WHT"喝道：“着！”双手连甩，团团火焰立时向着你激射而来！！！\n造成了 "HIR+damages+NOR+WHT" 点伤害。\n\n"NOR;
        break;
      case "巨石":
        msg_all = WHT"\n只听得$N"NOR+WHT"哈哈大笑一声，单掌在身前虚画一圆，一块"YEL"巨石"WHT"竟凭空生成！\n随着$N"NOR+WHT"一声断喝“着！”，石块带起巨大压迫之感，向着$n"NOR+WHT"砸去！！！\n\n"NOR;
        msg_me = WHT"\n你哈哈大笑一声，单掌在身前虚画一圆，一块"YEL"巨石"WHT"就此凭空生成！\n你大喝一声“着！”，念咒运劲，石块带起巨大压迫之感，向着$n"NOR+WHT"砸去！！！\n造成了 "HIG+damages+NOR+WHT" 点伤害。\n\n"NOR;
        msg_target = WHT"\n只听得$N"NOR+WHT"哈哈大笑一声，单掌在身前虚画一圆，一块"YEL"巨石"WHT"竟凭空生成！\n随着$N"NOR+WHT"一声断喝“着！”，石块带起巨大压迫之感，向着你砸了过来！！！\n造成了 "HIR+damages+NOR+WHT" 点伤害。\n\n"NOR;
        break;
    }
    return ([ "name": pfm_name, "damages": damages, "me_busy": Me_busy,"lost_hp": LostHP_pfm+random(LostHP_pfm),
          "msg_all": msg_all, "msg_me": msg_me, "msg_target": msg_target ]);
}
