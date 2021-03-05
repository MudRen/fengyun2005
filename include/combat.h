// combat.h

#ifndef __COMBAT__
#define __COMBAT__

#define TYPE_REGULAR	0
#define TYPE_RIPOSTE	1
#define TYPE_QUICK		2
#define TYPE_PERFORM	3

#define RESULT_UNKNOWN  0
#define RESULT_DODGE	-1
#define RESULT_PARRY	-2
#define RESULT_PROTECT  -3
#define RESULT_COUNTER  -4
#define RESULT_BLOCK    -5

// This is used as skill_power()'s argument to indicate which type of skill
// usage will be used in calculating skill power.
#define SKILL_USAGE_ATTACK		1
#define SKILL_USAGE_DODGE		2
#define SKILL_USAGE_PARRY		3
#define SKILL_USAGE_MOVE		4
#define SKILL_USAGE_MAGIC		5
#define SKILL_USAGE_SPELLS		6
#define SKILL_USAGE_CURSISM		7
#define SKILL_USAGE_HERB		8
#define SKILL_USAGE_PERCEPTION		9

#endif
