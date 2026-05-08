# Secure-by-Default Lab

A reference architecture for product security and EU Cyber Resilience Act (CRA) readiness, built on GitHub Advanced Security primitives (CodeQL, Dependabot, secret scanning) extended with a CRA-mapped portfolio dashboard.

## What this is

Six deliberately-mixed targets, each scanned continuously, demonstrating how a product security programme can use GitHub-native tooling to find vulnerabilities, manage dependencies, and report against CRA Annex I and Articles 13/14 obligations.

| Repo | Stack | What it demonstrates |
|---|---|---|
| `juliet-cpp` | NIST Juliet C/C++ subset | CodeQL on memory-safety bugs in compiled C/C++ |
| `juliet-csharp` | NIST Juliet C# subset | CodeQL on managed-code vulnerabilities |
| `windows-driver-samples` | Microsoft kernel-mode samples | CodeQL on Windows driver code, kernel-specific patterns |
| `webgoat-net-mvc` | Vulnerable ASP.NET MVC app | CodeQL + Dependabot on a real web stack |
| `thick-client-wpf` | Custom WPF desktop app | CodeQL on a desktop thick-client with deliberate flaws |
| `iiot-mqtt-broker` | Forked OSS MQTT broker | Real-world IIoT target, CodeQL + supply chain |
| `ghas-dashboard` | Aggregation layer | Cross-repo portfolio view with CRA mapping |

## Why this exists

The EU Cyber Resilience Act enters full enforcement in December 2027. Manufacturers of products with digital elements need to demonstrate vulnerability handling processes, secure-by-default design, and reporting capability. GitHub Advanced Security provides the raw primitives but doesn't speak CRA out of the box. This lab shows how to bridge that gap.

## Author

Built by Krupal, Product Security Lead and CRA-focused security testing practitioner.

---

*All findings shown here are intentional - the code targets are vulnerable by design (NIST Juliet, WebGoat, etc.) or contain deliberate flaws for demonstration.*
