// health_desc.h  健康描述   为了统一 qxd 和 npc 里的描述……
// naihe 05-9-1 11:35

string get_health_desc( int hp, int hp_max )
{
    if( hp >= hp_max )
        return HIG"看起来健康得很。"NOR;
    if( hp >= (hp_max *9/10) )
        return HIG"似乎受了点儿轻伤，不过毫无影响。"NOR;
    if( hp >= (hp_max *8/10) )
        return HIG"受了点儿轻伤，不过看起来还没什么大碍。"NOR;
    if( hp >= (hp_max *6/10) )
        return HIY"气息开始粗乱，看来似乎受了点儿轻伤。"NOR;
    if( hp >= (hp_max *5/10) )
        return HIY"大口大口地喘着粗气，看来情形不太妙了。"NOR;
    if( hp >= (hp_max *4/10) )
        return HIR"受伤严重，脚步凌乱，眼神散漫，看来需要好好休息一下了。"NOR;
    if( hp >= (hp_max *2/10) )
        return RED"已经受伤过重，一副随时就要倒下的样子。"NOR;
    if( hp >= (hp_max *1/10) )
        return RED"已经几欲倒地，只剩下最后一点气息在苦苦维系着。"NOR;
    return RED"已经失去了意识，看来是要不行了。"NOR;
}
