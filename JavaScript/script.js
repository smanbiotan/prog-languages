import { useState } from "react";

const steps = [
  {
    id: 1,
    phase: "BEFORE YOU RECORD",
    icon: "📋",
    color: "#f59e0b",
    sections: [
      {
        title: "Setup Checklist",
        type: "checklist",
        items: [
          "Wear your PE uniform or workout clothes",
          "Find a spacious, well-lit area",
          "Set camera in LANDSCAPE (horizontal) mode",
          "Make sure your FULL BODY is visible",
          "Stabilize your camera (prop it or use a tripod)",
          "Prepare drinking water nearby",
          "Have your phone or a clock nearby to track time",
          "Do a test recording to check audio and lighting",
          "Practice your intro speech once before recording",
        ],
      },
      {
        title: "What to Prepare",
        type: "note",
        content:
          "Know your exercises by heart before recording. Review the exercise reference videos provided. Remember: you'll add the timer and music in editing AFTER recording.",
      },
    ],
  },
  {
    id: 2,
    phase: "PART 1 – INTRODUCTION",
    icon: "🎤",
    color: "#6366f1",
    duration: "~2–3 minutes",
    sections: [
      {
        title: "Script (say this to the camera)",
        type: "script",
        lines: [
          {
            label: "Greeting",
            text: "Good [morning/afternoon/evening]! My name is [FULL NAME], from Section [SECTION].",
          },
          {
            label: "What is HIIT",
            text: "For my PATHFIT 2 Midterm Exam, I will be demonstrating a HIIT workout — or High-Intensity Interval Training. HIIT is a type of exercise that alternates short bursts of intense activity with brief rest periods. It helps improve cardiovascular endurance, build muscular strength, burn calories efficiently, and save time while exercising.",
          },
          {
            label: "What is Tabata",
            text: "The format I will be using is called Tabata — originally developed by Japanese scientist Izumi Tabata. For this exam, the Tabata method is modified for beginners: each exercise will be performed for 2 sets, with 10 seconds of rest between sets, and 30 seconds of rest before moving to the next exercise.",
          },
          {
            label: "Workout Overview",
            text: "My workout today consists of three parts: a 5-minute Warm-Up, 6 to 7 minutes of Conditioning Exercises, and a 5-minute Cool Down.",
          },
          {
            label: "Exercise Introduction",
            text: "The conditioning exercises I will perform are: Number 1 — Squat + Calf Raises, targeting the hamstrings, quadriceps, glutes, and calves. 2 sets of 20 reps, 10 seconds rest between sets, 30 seconds rest after. Number 2 — Mountain Climbers, targeting the core. 1 set of 20 reps, 30 seconds rest after. Number 3 — Straight Arm Plank + Pike Position, targeting the chest, triceps, and shoulders. 2 sets of 20 reps, 10 seconds rest between sets, 30 seconds after. Number 4 — Scissor Kicks, targeting the core. 2 sets of 20 reps, 10 seconds rest between sets, 30 seconds after. And Number 5 — Scissor Jumps, targeting the hamstrings, quadriceps, glutes, and calves. 1 set of 20 reps, 30 seconds rest after.",
          },
          {
            label: "Transition",
            text: "Let us now begin with the warm-up.",
          },
        ],
      },
    ],
  },
  {
    id: 3,
    phase: "PART 2 – WARM-UP",
    icon: "🔥",
    color: "#ef4444",
    duration: "5 minutes",
    sections: [
      {
        title: "Say Before Starting",
        type: "script",
        lines: [
          {
            label: "Intro",
            text: "We will now begin the warm-up. This warm-up targets all the major muscle groups we will be using today — hamstrings, quadriceps, glutes, calves, core, chest, shoulders, and triceps. Each exercise will be done for about 30 to 40 seconds.",
          },
        ],
      },
      {
        title: "Warm-Up Exercises (do in order)",
        type: "exercise-list",
        items: [
          {
            name: "Leg Swings (Forward & Back)",
            duration: "30–40 sec each leg",
            muscles: "Hamstrings, Glutes",
            cue: "Hold a wall for balance. Swing one leg forward and back in a controlled motion.",
          },
          {
            name: "Lateral Leg Swings",
            duration: "30–40 sec each leg",
            muscles: "Quadriceps, Hips",
            cue: "Face the wall, swing leg side to side.",
          },
          {
            name: "Walking Lunges",
            duration: "30–40 sec",
            muscles: "Quads, Glutes, Hamstrings",
            cue: "Step forward, lower your back knee toward the floor. Keep chest upright.",
          },
          {
            name: "Slow Calf Raises",
            duration: "30–40 sec",
            muscles: "Calves",
            cue: "Rise up slowly on your toes, lower back down with control.",
          },
          {
            name: "Slow High Knees",
            duration: "30–40 sec",
            muscles: "Core, Legs",
            cue: "March in place lifting knees to hip level. Keep core tight.",
          },
          {
            name: "Arm Circles (Forward & Back)",
            duration: "30 sec",
            muscles: "Shoulders, Chest",
            cue: "Extend arms wide. Small to big circles forward, then reverse.",
          },
          {
            name: "Tricep Stretch with Reach",
            duration: "30 sec each arm",
            muscles: "Triceps, Shoulders",
            cue: "Raise one arm, bend elbow behind head, use other hand to gently push elbow down.",
          },
          {
            name: "Torso Twist",
            duration: "30–40 sec",
            muscles: "Core, Chest",
            cue: "Feet shoulder-width apart, arms extended. Rotate torso left and right.",
          },
        ],
      },
    ],
  },
  {
    id: 4,
    phase: "PART 3 – CONDITIONING",
    icon: "💪",
    color: "#10b981",
    duration: "6–7 minutes",
    sections: [
      {
        title: "Say Before Starting",
        type: "script",
        lines: [
          {
            label: "Intro",
            text: "We will now move on to the conditioning exercises. Remember: proper form is more important than speed. Let's begin.",
          },
        ],
      },
      {
        title: "Conditioning Exercises (do in exact order)",
        type: "conditioning",
        items: [
          {
            number: 1,
            name: "Squat + Calf Raises",
            muscles: "Hamstrings, Quadriceps, Glutes, Calves",
            sets: 2,
            reps: 20,
            restBetween: "10 sec",
            restAfter: "30 sec",
            cue: "Stand feet shoulder-width. Squat down, rise up, then go up on your toes for the calf raise. That's 1 rep.",
            announce: "Exercise 1 — Squat plus Calf Raises. 2 sets, 20 reps. Targets the hamstrings, quadriceps, glutes, and calves.",
          },
          {
            number: 2,
            name: "Mountain Climbers",
            muscles: "Core",
            sets: 1,
            reps: 20,
            restBetween: null,
            restAfter: "30 sec",
            cue: "Start in a plank position. Drive one knee toward your chest, alternate quickly. Each knee drive = 1 rep.",
            announce: "Exercise 2 — Mountain Climbers. 1 set, 20 reps. Targets the core.",
          },
          {
            number: 3,
            name: "Straight Arm Plank + Pike",
            muscles: "Chest, Triceps, Shoulders",
            sets: 2,
            reps: 20,
            restBetween: "10 sec",
            restAfter: "30 sec",
            cue: "From straight arm plank, push your hips up into an inverted-V (pike), then return to plank. That's 1 rep.",
            announce: "Exercise 3 — Straight Arm Plank plus Pike Position. 2 sets, 20 reps. Targets the chest, triceps, and shoulders.",
          },
          {
            number: 4,
            name: "Scissor Kicks",
            muscles: "Core",
            sets: 2,
            reps: 20,
            restBetween: "10 sec",
            restAfter: "30 sec",
            cue: "Lie on your back, hands under glutes. Lift both legs and alternate crossing them up and down like scissors. Each crossing = 1 rep.",
            announce: "Exercise 4 — Scissor Kicks. 2 sets, 20 reps. Targets the core.",
          },
          {
            number: 5,
            name: "Scissor Jumps",
            muscles: "Hamstrings, Quadriceps, Glutes, Calves",
            sets: 1,
            reps: 20,
            restBetween: null,
            restAfter: "30 sec",
            cue: "Stand in a lunge position. Jump and switch legs in the air. Land softly with control. Each switch = 1 rep.",
            announce: "Exercise 5 — Scissor Jumps. 1 set, 20 reps. Targets the hamstrings, quadriceps, glutes, and calves.",
          },
        ],
      },
    ],
  },
  {
    id: 5,
    phase: "PART 4 – COOL DOWN",
    icon: "🧘",
    color: "#3b82f6",
    duration: "5 minutes",
    sections: [
      {
        title: "Say Before Starting",
        type: "script",
        lines: [
          {
            label: "Intro",
            text: "Great work! We will now move into the cool down. Hold each stretch for 20 to 30 seconds. Breathe in through your nose and out through your mouth.",
          },
        ],
      },
      {
        title: "Cool Down Stretches (hold each 20–30 sec)",
        type: "exercise-list",
        items: [
          {
            name: "Standing Forward Fold",
            duration: "20–30 sec",
            muscles: "Hamstrings",
            cue: "Stand tall, hinge forward at the hips, let your arms hang or grab your shins. Relax your neck.",
          },
          {
            name: "Standing Quad Stretch",
            duration: "20–30 sec each leg",
            muscles: "Quadriceps",
            cue: "Balance on one foot, grab your ankle behind you, keep knees together.",
          },
          {
            name: "Figure-4 Stretch",
            duration: "20–30 sec each side",
            muscles: "Glutes",
            cue: "Cross one ankle over the opposite knee, sit back slightly or lie on your back and pull legs toward you.",
          },
          {
            name: "Standing Calf Stretch",
            duration: "20–30 sec each leg",
            muscles: "Calves",
            cue: "Step one foot back, press heel into the floor, lean forward gently.",
          },
          {
            name: "Knee-to-Chest Stretch",
            duration: "20–30 sec each leg",
            muscles: "Core, Lower Back",
            cue: "Lie on your back, pull one knee to your chest and hold. Switch sides.",
          },
          {
            name: "Chest Opener",
            duration: "20–30 sec",
            muscles: "Chest",
            cue: "Clasp hands behind your back, squeeze shoulder blades together, lift chest.",
          },
          {
            name: "Cross-Body Shoulder Stretch",
            duration: "20–30 sec each arm",
            muscles: "Shoulders",
            cue: "Extend one arm across your chest, use the other hand to press gently above the elbow.",
          },
          {
            name: "Overhead Tricep Stretch",
            duration: "20–30 sec each arm",
            muscles: "Triceps",
            cue: "Raise arm, bend elbow behind your head. Use opposite hand to gently push elbow down.",
          },
        ],
      },
    ],
  },
  {
    id: 6,
    phase: "PART 5 – OUTRO",
    icon: "🎬",
    color: "#8b5cf6",
    sections: [
      {
        title: "Script (say something like this)",
        type: "script",
        lines: [
          {
            label: "Closing",
            text: "And that concludes my PATHFIT 2 Midterm Exam performance. Today we completed a full HIIT Tabata workout consisting of a warm-up, five conditioning exercises, and a cool down. I hope this demonstrates my understanding of HIIT and proper exercise technique. Thank you for watching, and I hope you have a great day! This is [YOUR NAME], signing off.",
          },
        ],
      },
    ],
  },
  {
    id: 7,
    phase: "AFTER RECORDING – EDITING",
    icon: "✂️",
    color: "#f97316",
    sections: [
      {
        title: "Editing Checklist",
        type: "checklist",
        items: [
          "Add a visible timer overlay during ALL parts (warm-up, conditioning, rest, cool down)",
          "Timer must be accurate and match the correct intervals",
          "Place timer in a corner so it doesn't block your body",
          "Add Tabata Songs music ONLY during the conditioning part",
          "Make sure your voice is NOT overpowered by the music",
          "Video must still appear continuous even after editing",
          "Watch the full video once to check quality before submitting",
        ],
      },
      {
        title: "Submission",
        type: "note",
        content:
          "File name: Lastname_Firstname-Section_M.exam\nUpload to the Google Drive link provided by your instructor.\nUse your CArSU email.\nDeadline: April 25 (Saturday), 11:00 PM",
      },
    ],
  },
];

export default function PathfitGuide() {
  const [activeStep, setActiveStep] = useState(0);
  const [checked, setChecked] = useState({});

  const step = steps[activeStep];

  const toggleCheck = (key) => {
    setChecked((prev) => ({ ...prev, [key]: !prev[key] }));
  };

  return (
    <div style={{
      fontFamily: "'Georgia', serif",
      background: "#0f0f13",
      minHeight: "100vh",
      color: "#e8e4dc",
      display: "flex",
      flexDirection: "column",
    }}>
      {/* Header */}
      <div style={{
        background: "linear-gradient(135deg, #1a1a2e 0%, #16213e 100%)",
        borderBottom: "1px solid #2a2a3e",
        padding: "20px 24px 16px",
        position: "sticky",
        top: 0,
        zIndex: 100,
      }}>
        <div style={{ fontSize: 11, letterSpacing: 3, color: "#6366f1", fontFamily: "monospace", marginBottom: 4 }}>
          PATHFIT 2 · MIDTERM EXAM
        </div>
        <div style={{ fontSize: 20, fontWeight: "bold", color: "#f8f4ec" }}>
          Video Recording Guide
        </div>
      </div>

      {/* Step Nav */}
      <div style={{
        display: "flex",
        overflowX: "auto",
        gap: 8,
        padding: "12px 20px",
        background: "#111118",
        borderBottom: "1px solid #1e1e2e",
      }}>
        {steps.map((s, i) => (
          <button
            key={s.id}
            onClick={() => setActiveStep(i)}
            style={{
              flexShrink: 0,
              padding: "6px 14px",
              borderRadius: 20,
              border: "none",
              cursor: "pointer",
              fontSize: 12,
              fontFamily: "monospace",
              background: activeStep === i ? s.color : "#1e1e2e",
              color: activeStep === i ? "#0f0f13" : "#9990a8",
              fontWeight: activeStep === i ? "bold" : "normal",
              transition: "all 0.2s",
            }}
          >
            {s.icon} {s.id === 1 ? "Pre-Shoot" : s.id === 7 ? "Editing" : `Part ${s.id - 1}`}
          </button>
        ))}
      </div>

      {/* Content */}
      <div style={{ flex: 1, padding: "20px 20px 40px", maxWidth: 720, margin: "0 auto", width: "100%" }}>
        {/* Phase Header */}
        <div style={{
          display: "flex",
          alignItems: "center",
          gap: 12,
          marginBottom: 24,
        }}>
          <div style={{
            width: 48,
            height: 48,
            borderRadius: 12,
            background: step.color + "22",
            border: `2px solid ${step.color}`,
            display: "flex",
            alignItems: "center",
            justifyContent: "center",
            fontSize: 22,
          }}>
            {step.icon}
          </div>
          <div>
            <div style={{ fontSize: 11, color: step.color, letterSpacing: 2, fontFamily: "monospace" }}>
              STEP {step.id} OF {steps.length}
            </div>
            <div style={{ fontSize: 20, fontWeight: "bold", color: "#f8f4ec" }}>
              {step.phase}
            </div>
            {step.duration && (
              <div style={{ fontSize: 12, color: "#6b6b80", marginTop: 2 }}>
                ⏱ {step.duration}
              </div>
            )}
          </div>
        </div>

        {step.sections.map((section, si) => (
          <div key={si} style={{ marginBottom: 28 }}>
            <div style={{
              fontSize: 11,
              letterSpacing: 2,
              color: step.color,
              fontFamily: "monospace",
              marginBottom: 12,
              textTransform: "uppercase",
            }}>
              {section.title}
            </div>

            {/* CHECKLIST */}
            {section.type === "checklist" && (
              <div style={{ display: "flex", flexDirection: "column", gap: 8 }}>
                {section.items.map((item, ii) => {
                  const key = `${si}-${ii}`;
                  return (
                    <div
                      key={ii}
                      onClick={() => toggleCheck(key)}
                      style={{
                        display: "flex",
                        alignItems: "flex-start",
                        gap: 12,
                        padding: "10px 14px",
                        background: checked[key] ? "#1a2a1a" : "#16161e",
                        border: `1px solid ${checked[key] ? "#2d5a2d" : "#2a2a3e"}`,
                        borderRadius: 8,
                        cursor: "pointer",
                        transition: "all 0.2s",
                      }}
                    >
                      <div style={{
                        width: 18,
                        height: 18,
                        borderRadius: 4,
                        border: `2px solid ${checked[key] ? "#4ade80" : "#4a4a5e"}`,
                        background: checked[key] ? "#4ade80" : "transparent",
                        flexShrink: 0,
                        marginTop: 1,
                        display: "flex",
                        alignItems: "center",
                        justifyContent: "center",
                        fontSize: 11,
                      }}>
                        {checked[key] ? "✓" : ""}
                      </div>
                      <div style={{
                        fontSize: 14,
                        color: checked[key] ? "#6b7a6b" : "#c8c4bc",
                        textDecoration: checked[key] ? "line-through" : "none",
                        lineHeight: 1.5,
                      }}>
                        {item}
                      </div>
                    </div>
                  );
                })}
              </div>
            )}

            {/* NOTE */}
            {section.type === "note" && (
              <div style={{
                padding: "14px 16px",
                background: "#1a1a28",
                border: `1px solid ${step.color}44`,
                borderLeft: `3px solid ${step.color}`,
                borderRadius: 8,
                fontSize: 14,
                color: "#b8b4ac",
                lineHeight: 1.7,
                whiteSpace: "pre-line",
              }}>
                {section.content}
              </div>
            )}

            {/* SCRIPT */}
            {section.type === "script" && (
              <div style={{ display: "flex", flexDirection: "column", gap: 12 }}>
                {section.lines.map((line, li) => (
                  <div key={li} style={{
                    background: "#16161e",
                    border: "1px solid #2a2a3e",
                    borderRadius: 10,
                    overflow: "hidden",
                  }}>
                    <div style={{
                      background: step.color + "18",
                      padding: "6px 14px",
                      fontSize: 10,
                      fontFamily: "monospace",
                      letterSpacing: 1.5,
                      color: step.color,
                    }}>
                      {line.label.toUpperCase()}
                    </div>
                    <div style={{
                      padding: "12px 14px",
                      fontSize: 14,
                      color: "#d8d4cc",
                      lineHeight: 1.8,
                      fontStyle: "italic",
                    }}>
                      "{line.text}"
                    </div>
                  </div>
                ))}
              </div>
            )}

            {/* EXERCISE LIST (warm-up / cool down) */}
            {section.type === "exercise-list" && (
              <div style={{ display: "flex", flexDirection: "column", gap: 10 }}>
                {section.items.map((ex, ei) => (
                  <div key={ei} style={{
                    background: "#16161e",
                    border: "1px solid #2a2a3e",
                    borderRadius: 10,
                    padding: "12px 14px",
                  }}>
                    <div style={{ display: "flex", justifyContent: "space-between", alignItems: "flex-start", gap: 8 }}>
                      <div style={{ fontSize: 15, fontWeight: "bold", color: "#f0ece4" }}>
                        {ex.name}
                      </div>
                      <div style={{
                        fontSize: 11,
                        background: step.color + "22",
                        color: step.color,
                        padding: "3px 8px",
                        borderRadius: 10,
                        flexShrink: 0,
                        fontFamily: "monospace",
                      }}>
                        {ex.duration}
                      </div>
                    </div>
                    <div style={{ fontSize: 12, color: "#6b6b80", marginTop: 3, marginBottom: 6, fontFamily: "monospace" }}>
                      🎯 {ex.muscles}
                    </div>
                    <div style={{ fontSize: 13, color: "#9890a0", lineHeight: 1.6 }}>
                      {ex.cue}
                    </div>
                  </div>
                ))}
              </div>
            )}

            {/* CONDITIONING */}
            {section.type === "conditioning" && (
              <div style={{ display: "flex", flexDirection: "column", gap: 14 }}>
                {section.items.map((ex) => (
                  <div key={ex.number} style={{
                    background: "#16161e",
                    border: "1px solid #2a2a3e",
                    borderRadius: 12,
                    overflow: "hidden",
                  }}>
                    <div style={{
                      background: step.color + "18",
                      padding: "8px 14px",
                      display: "flex",
                      alignItems: "center",
                      gap: 10,
                    }}>
                      <div style={{
                        width: 26,
                        height: 26,
                        borderRadius: "50%",
                        background: step.color,
                        color: "#0f0f13",
                        display: "flex",
                        alignItems: "center",
                        justifyContent: "center",
                        fontWeight: "bold",
                        fontSize: 13,
                        flexShrink: 0,
                      }}>
                        {ex.number}
                      </div>
                      <div style={{ fontSize: 15, fontWeight: "bold", color: "#f0ece4" }}>
                        {ex.name}
                      </div>
                    </div>
                    <div style={{ padding: "12px 14px" }}>
                      <div style={{ fontSize: 12, color: "#6b6b80", fontFamily: "monospace", marginBottom: 10 }}>
                        🎯 {ex.muscles}
                      </div>
                      <div style={{ display: "flex", gap: 8, flexWrap: "wrap", marginBottom: 10 }}>
                        {[
                          { label: "SETS", val: ex.sets },
                          { label: "REPS", val: ex.reps },
                          { label: "REST/SET", val: ex.restBetween ?? "N/A" },
                          { label: "REST AFTER", val: ex.restAfter },
                        ].map((stat) => (
                          <div key={stat.label} style={{
                            background: "#1e1e2e",
                            borderRadius: 6,
                            padding: "5px 10px",
                            textAlign: "center",
                          }}>
                            <div style={{ fontSize: 9, color: "#6b6b80", letterSpacing: 1, fontFamily: "monospace" }}>
                              {stat.label}
                            </div>
                            <div style={{ fontSize: 14, color: step.color, fontWeight: "bold" }}>
                              {stat.val}
                            </div>
                          </div>
                        ))}
                      </div>
                      <div style={{
                        fontSize: 13,
                        color: "#9890a0",
                        lineHeight: 1.6,
                        marginBottom: 10,
                      }}>
                        <span style={{ color: "#6b6b80", fontFamily: "monospace", fontSize: 11 }}>HOW TO: </span>
                        {ex.cue}
                      </div>
                      <div style={{
                        background: "#1e1e2e",
                        borderRadius: 8,
                        padding: "10px 12px",
                        borderLeft: `3px solid ${step.color}`,
                      }}>
                        <div style={{ fontSize: 10, color: "#6b6b80", letterSpacing: 1.5, fontFamily: "monospace", marginBottom: 5 }}>
                          SAY BEFORE THIS EXERCISE
                        </div>
                        <div style={{ fontSize: 13, color: "#c8c4bc", lineHeight: 1.7, fontStyle: "italic" }}>
                          "{ex.announce}"
                        </div>
                      </div>
                    </div>
                  </div>
                ))}
              </div>
            )}
          </div>
        ))}

        {/* Navigation */}
        <div style={{ display: "flex", gap: 10, marginTop: 16 }}>
          {activeStep > 0 && (
            <button
              onClick={() => setActiveStep(activeStep - 1)}
              style={{
                flex: 1,
                padding: "12px",
                background: "#1e1e2e",
                border: "1px solid #2a2a3e",
                borderRadius: 10,
                color: "#9890a0",
                fontSize: 14,
                cursor: "pointer",
              }}
            >
              ← Previous
            </button>
          )}
          {activeStep < steps.length - 1 && (
            <button
              onClick={() => setActiveStep(activeStep + 1)}
              style={{
                flex: 1,
                padding: "12px",
                background: step.color,
                border: "none",
                borderRadius: 10,
                color: "#0f0f13",
                fontSize: 14,
                fontWeight: "bold",
                cursor: "pointer",
              }}
            >
              Next →
            </button>
          )}
        </div>
      </div>
    </div>
  );
}
