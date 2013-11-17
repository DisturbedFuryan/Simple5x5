#ifndef UTILITIES_HPP
#define UTILITIES_HPP

/* Training duration expressed in weeks. */
const int g_weekNum = 12;

/* The week in which you come face-to-face with your five rep max. */
const int g_weekWithFiveRepMax = 5;

/* Multipliers for the first four sets. */
const float g_setMultiplier[4] = { 0.6f, 0.7f, 0.8f, 0.9f };

/* Converter from the one to the five rep max. */
const float g_oneRepToFiveMultiplier = 0.85f;

/* The accuracy with which you can put weight on your gym. */
const float g_weightAccuracy = 2.5f;

/* The treshold specifying when you can come face-to-face with more weight. */
const float g_treshold = ((2.0f / 3.0f) * g_weightAccuracy);

#endif
